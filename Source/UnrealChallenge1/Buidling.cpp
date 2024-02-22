// Fill out your copyright notice in the Description page of Project Settings.


#include "Buidling.h"

// Sets default values
ABuilding::ABuilding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetRootComponent(CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh")));

}

// Called when the game starts or when spawned
void ABuilding::BeginPlay()
{
	Super::BeginPlay();
	this->isActive = true;
}

void ABuilding::StartProduction()
{
}

void ABuilding::StopProduction()
{
}

void ABuilding::CheckInputMats()
{
}

void ABuilding::LoadMaterials(ATruck* truck)
{
}

void ABuilding::UnloadMaterials(ATruck* truck)
{
}

// Called every frame
void ABuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

