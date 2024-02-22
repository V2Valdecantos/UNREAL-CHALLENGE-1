// Fill out your copyright notice in the Description page of Project Settings.


#include "SewingFactory.h"

// Sets default values
ASewingFactory::ASewingFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASewingFactory::BeginPlay()
{
	Super::BeginPlay();
	this->BoxCollider = this->FindComponentByClass<UBoxComponent>();
	if (this->BoxCollider != nullptr)
	{
		this->BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &ASewingFactory::BeginOverlap);
		this->BoxCollider->OnComponentEndOverlap.AddDynamic(this, &ASewingFactory::EndOverlap);
	}

	this->gameMode = Cast<AResourceManagementGameMode>(GetWorld()->GetAuthGameMode());
	
}

void ASewingFactory::StartProduction()
{
	this->isActive = true;
}

void ASewingFactory::StopProduction()
{
	this->isActive = false;
}

void ASewingFactory::LoadMaterials(ATruck* truck)
{
}

void ASewingFactory::UnloadMaterials(ATruck* truck)
{
	truck->isLoading = true;
	if (truck->carriedResource == STEEL_BEAM && truck->cargo > 0)
	{
		this->inputCount1 += truck->cargo;

		if (this->inputCount1 > 3)
		{
			this->inputCount1 = 3;
		}

		truck->cargo = 0;
		truck->carriedResource = EResourceType::EMPTY;
	}
	else if (truck->carriedResource == WOOD && truck->cargo > 0)
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
void ASewingFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Super::Tick(DeltaTime);
	if (this->isActive && this->inputCount1 > 0 && this->inputCount2 > 0)
	{
		this->fTicks += DeltaTime;

		if (this->fTicks >= this->productionTime)
		{
			this->resourceCount += 1;
			this->inputCount1 -= 1;
			this->inputCount2 -= 1;
			this->fTicks = 0.0f;
			UE_LOG(LogTemp, Display, TEXT("SEWING MACHINES PRODUCED: %d"), this->resourceCount);
		}
	}

	this->gameMode->UpdateSewingText(this->resourceCount, this->inputCount1, this->inputCount2);

}

void ASewingFactory::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ATruck* truck = Cast<ATruck>(OtherActor);

	if (truck != NULL)
	{

		if (!truck->isColliding)
		{
			UE_LOG(LogTemp, Display, TEXT("SEWING OVERLAP BEGIN"));
			truck->isColliding = true;
			truck->currentBuilding = EBuildingType::FACTORY;

			//unload the truck if ready
			if (truck->carriedResource == WOOD || truck->carriedResource == STEEL_BEAM)
			{
				this->UnloadMaterials(truck);
				int32 randomizer = FMath::RandRange(0, 2);

				if (randomizer == 0)
				{
					this->TruckController->SetDestination(truck, truck->currentBuilding, EBuildingType::COAL_MINE);
				}
				else if (randomizer == 1)
				{
					this->TruckController->SetDestination(truck, truck->currentBuilding, EBuildingType::IRON_MINE);
				}
				else
				{
					this->TruckController->SetDestination(truck, truck->currentBuilding, EBuildingType::LUMBER_YARD);
				}
			}
			else //else go to the next building
			{
				int32 randomizer = FMath::RandRange(0, 1);

				if (randomizer == 0)
				{
					this->TruckController->SetDestination(truck, truck->currentBuilding, EBuildingType::COAL_MINE);
				}
				else
				{
					this->TruckController->SetDestination(truck, truck->currentBuilding, EBuildingType::IRON_MINE);
				}
				
			}
		}
	}

}

void ASewingFactory::EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ATruck* truck = Cast<ATruck>(OtherActor);
	if (truck != NULL)
		truck->isColliding = false;
}

