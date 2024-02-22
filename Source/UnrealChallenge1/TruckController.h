// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spline.h"
#include "Truck.h"
#include "GameFramework/Actor.h"
#include "TruckController.generated.h"

UCLASS()
class UNREALCHALLENGE1_API ATruckController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATruckController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetDestination(ATruck* truck, EBuildingType currentLocation, EBuildingType destination);

private:

	float fTicks = 0.0f;

	UPROPERTY(EditAnywhere) TArray<ASpline*> coalMineSplines;
	UPROPERTY(EditAnywhere) TArray<ASpline*> ironMineSplines;
	UPROPERTY(EditAnywhere) TArray<ASpline*> furnaceSplines;
	UPROPERTY(EditAnywhere) TArray<ASpline*> lumberSplines;
	UPROPERTY(EditAnywhere) TArray<ASpline*> sewingSplines;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true")) ATruck* Truck1;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true")) ATruck* Truck2;

};
