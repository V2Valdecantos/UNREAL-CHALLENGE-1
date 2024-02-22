// Fill out your copyright notice in the Description page of Project Settings.


#include "Furnace.h"

// Sets default values
AFurnace::AFurnace()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFurnace::BeginPlay()
{
	Super::BeginPlay();
	this->BoxCollider = this->FindComponentByClass<UBoxComponent>();
	if (this->BoxCollider != nullptr)
	{
		this->BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AFurnace::BeginOverlap);
		this->BoxCollider->OnComponentEndOverlap.AddDynamic(this, &AFurnace::EndOverlap);
	}

	this->gameMode = Cast<AResourceManagementGameMode>(GetWorld()->GetAuthGameMode());
}

void AFurnace::StartProduction()
{
	this->isActive = true;
}

void AFurnace::StopProduction()
{
	this->isActive = false;
}

void AFurnace::LoadMaterials(ATruck* truck)
{
	if (truck->carriedResource == EMPTY && this->resourceCount > 0)
	{
		truck->isLoading = true;
		truck->cargo += this->resourceCount;

		if (truck->cargo > truck->capacity)
		{
			truck->cargo = truck->capacity;
		}

		this->resourceCount = 0;
		truck->carriedResource = EResourceType::STEEL_BEAM;
		this->TruckController->SetDestination(truck, truck->currentBuilding, EBuildingType::FACTORY);
	}
}

void AFurnace::UnloadMaterials(ATruck* truck)
{
	truck->isLoading = true;
	if (truck->carriedResource == IRON && truck->cargo > 0)
	{
		this->inputCount1 += truck->cargo;

		if (this->inputCount1 > 3)
		{
			this->inputCount1 = 3;
		}

		truck->cargo = 0;
		truck->carriedResource = EResourceType::EMPTY;
	}
	else if (truck->carriedResource == COAL && truck->cargo > 0)
	{
		this->inputCount2 += truck->cargo;

		if (this->inputCount2 > 3)
		{
			this->inputCount2 = 3;
		}

		truck->cargo = 0;
		truck->carriedResource = EResourceType::EMPTY;
	}
}

// Called every frame
void AFurnace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (this->isActive && this->inputCount1 > 0 && this->inputCount2 > 0)
	{
		this->fTicks += DeltaTime;

		if (this->fTicks >= this->productionTime)
		{
			if (this->resourceCount < 3)
			{
				this->resourceCount += 1;
				this->inputCount1 -= 1;
				this->inputCount2 -= 1;
				this->fTicks = 0.0f;
				UE_LOG(LogTemp, Display, TEXT("FRUNACE PRODUCED: %d"), this->resourceCount)
			}

		}
	}

	if (this->resourceCount >= 3)
	{
		this->StopProduction();
	}
	else
	{
		this->StartProduction();
	}

	this->gameMode->UpdateFurnaceText(this->resourceCount, this->inputCount1, this->inputCount2);
}

void AFurnace::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ATruck* truck = Cast<ATruck>(OtherActor);

	if (truck != NULL)
	{

		if (!truck->isColliding)
		{
			UE_LOG(LogTemp, Display, TEXT("FURNACE OVERLAP BEGIN"));
			truck->isColliding = true;
			truck->currentBuilding = EBuildingType::FURNACE;

			//load the truck if ready
			if (truck->cargo == 0 && truck->carriedResource == EResourceType::EMPTY && this->resourceCount > 0)
			{
				this->LoadMaterials(truck);
			}
			else if (truck->carriedResource == COAL || truck->carriedResource == IRON)
			{
				this->UnloadMaterials(truck);
				if (this->resourceCount > 0)
				{
					this->LoadMaterials(truck);
				}
				else
				{
					this->TruckController->SetDestination(truck, truck->currentBuilding, EBuildingType::LUMBER_YARD);
				}
			}
			else //else go to the next building
			{
				this->TruckController->SetDestination(truck, truck->currentBuilding, EBuildingType::LUMBER_YARD);
			}
		}
	}
}

void AFurnace::EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ATruck* truck = Cast<ATruck>(OtherActor);
	if (truck != NULL)
		truck->isColliding = false;
}

