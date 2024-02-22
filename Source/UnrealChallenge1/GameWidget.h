// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCHALLENGE1_API UGameWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite) int32 coal = 0;
	UPROPERTY(BlueprintReadWrite) int32 iron = 0;
	UPROPERTY(BlueprintReadWrite) int32 wood = 0;
	UPROPERTY(BlueprintReadWrite) int32 steelBeams = 0;
	UPROPERTY(BlueprintReadWrite) int32 furnaceInput1 = 0;
	UPROPERTY(BlueprintReadWrite) int32 furnaceInput2 = 0;
	UPROPERTY(BlueprintReadWrite) int32 sewingMachines = 0;
	UPROPERTY(BlueprintReadWrite) int32 sewingInput1 = 0;
	UPROPERTY(BlueprintReadWrite) int32 sewingInput2 = 0;

	//void UpdateText();	
	
};
