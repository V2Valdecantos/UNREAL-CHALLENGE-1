// Fill out your copyright notice in the Description page of Project Settings.


#include "IronMine.h"

// Sets default values
AIronMine::AIronMine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AIronMine::BeginPlay()
{
	Super::BeginPlay();
	this->BoxCollider = this->FindComponentByClass<UBoxComponent>();
	if (this->BoxCollider != nullptr)
	{
		this->BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AIronMine::BeginOverlap);
		this->BoxCollider->OnComponentEndOverlap.AddDynamic(this, &AIronMine::EndOverlap);
	}

	this->gameMode = Cast<AResourceManagementGameMode>(GetWorld()->GetAuthGameMode());
}

void AIronMine::StartProduction()
{
	this->isActive = true;
}

void AIronMine::StopProduction()
{
	this->isActive = false;
}

void AIronMine::LoadMaterials(ATruck* truck)
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
		truck->carriedResource = EResourceType::IRON;
		this->TruckController->SetDestination(truck, truck->currentBuilding, EBuildingType::FURNACE);
	}
}

// Called every frame
void AIronMine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (this->isActive)
	{
		this->fTicks += DeltaTime;

		if (this->fTicks >= this->productionTime)
		{
			if (this->resourceCount < 3)
			{
				this->resourceCount += 1;
				this->fTicks = 0.0f;
				UE_LOG(LogTemp, Display, TEXT("IRON PRODUCED: %d"), this->resourceCount)
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

	this->gameMode->UpdateIronMineText(this->resourceCount);
}

void AIronMine::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	ATruck* truck = Cast<ATruck>(OtherActor);

	if (truck != NULL)
	{

		if (!truck->isColliding)
		{
			UE_LOG(LogTemp, Display, TEXT("IRON MINE OVERLAP BEGIN"));
			truck->isColliding = true;
			truck->currentBuilding = EBuildingType::IRON_MINE;

			//load the truck if ready
			if (truck->cargo == 0 && truck->carriedResource == EResourceType::EMPTY && this->resourceCount > 0)
			{
				this->LoadMaterials(truck);
			}
			else //else go to the next building
			{
				this->TruckController->SetDestination(truck, truck->currentBuilding, EBuildingType::FURNACE);
			}
		}
	}
}

void AIronMine::EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ATruck* truck = Cast<ATruck>(OtherActor);
	if (truck != NULL)
		truck->isColliding = false;	
}

