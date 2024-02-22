// Fill out your copyright notice in the Description page of Project Settings.


#include "Truck.h"

// Sets default values
ATruck::ATruck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATruck::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATruck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!this->isLoading)	
	{
		this->Move();
	}
	 
	if (this->isLoading)
	{
		this->loadingTime = FMath::RandRange(1, 3);
		this->fTicks += DeltaTime;
		
		if (this->fTicks >= this->loadingTime)
		{
			UE_LOG(LogTemp, Display, TEXT("DONE LOADING"));
			this->isLoading = false;
			this->fTicks = 0.0f;
		}
	}
}


