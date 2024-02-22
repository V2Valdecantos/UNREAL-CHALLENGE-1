// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TruckController.h"
#include "Engine/GameInstance.h"
#include "NavigationManager.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCHALLENGE1_API UNavigationManager : public UGameInstance
{
	GENERATED_BODY()

public:
	ATruckController* TruckController;
	
};
