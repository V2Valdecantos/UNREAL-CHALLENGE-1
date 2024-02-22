// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TruckController.h"
#include "ResourceManagementGameMode.h"
#include "Components/BoxComponent.h"
#include "Buidling.generated.h"

UCLASS()
class UNREALCHALLENGE1_API ABuilding : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void StartProduction();
	virtual void StopProduction();
	virtual void CheckInputMats();

	virtual void LoadMaterials(ATruck* truck);
	virtual void UnloadMaterials(ATruck* truck);

	AResourceManagementGameMode* gameMode = nullptr;

	UPROPERTY(EditAnywhere) UBoxComponent* BoxCollider = nullptr;
	UPROPERTY(EditAnywhere) ATruckController* TruckController = nullptr;

	EBuildingType buildingType = EBuildingType::NONE;
	EResourceType resourceType = EResourceType::EMPTY;
	bool hasMats = false;
	bool isActive = false;
	float fTicks = 0.0f;

	int resourceCount = 0;
	int inputCount1 = 0;
	int inputCount2 = 0;

	UPROPERTY(EditAnywhere) float productionTime = 5.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};


