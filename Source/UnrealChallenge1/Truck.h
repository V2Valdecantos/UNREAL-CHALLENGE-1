// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spline.h"
#include "GameFramework/Actor.h"
#include "Truck.generated.h"


UENUM()
enum EResourceType
{
	COAL,
	IRON,
	WOOD,
	STEEL_BEAM,
	SEWING_MACHINE,
	EMPTY
};

UENUM()
enum EBuildingType
{
	COAL_MINE,
	IRON_MINE,
	LUMBER_YARD,
	FURNACE,
	FACTORY,
	NONE
};

UCLASS()
class UNREALCHALLENGE1_API ATruck : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATruck();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable) void Move();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable) void ToggleMove();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable) void ResetSpline();

public:

	bool isActive = true;
	bool isColliding = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true")) bool isLoading = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true")) ASpline* currentPath;
	UPROPERTY(EditAnywhere) float loadingTime = 2.0f;
	UPROPERTY(EditAnywhere) int capacity = 3.0f;

	EResourceType carriedResource = EResourceType::EMPTY;
	EBuildingType currentBuilding = EBuildingType::NONE;
	int cargo = 0;
	float fTicks = 0.0f;

	
};
