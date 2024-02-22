// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameWidget.h"
#include "ResourceManagementGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCHALLENGE1_API AResourceManagementGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	int32 coal = 0;
	int32 iron = 0;
	int32 wood = 0;
	int32 steelBeams = 0;
	int32 furnaceInput1 = 0;
	int32 furnaceInput2 = 0;
	int32 sewingMachines = 0;
	int32 sewingInput1 = 0;
	int32 sewingInput2 = 0;

	UPROPERTY(EditAnywhere, Category="Widgets")
	TSubclassOf <class UUserWidget> gameWidgetClass;

	UPROPERTY()
	UGameWidget* gameWidget;

	virtual void BeginPlay() override;

	void UpdateText();

public:

	void UpdateCoalMineText(int32 coalCount);
	void UpdateIronMineText(int32 ironCount);
	void UpdateLumberYardText(int32 woodCount);
	void UpdateFurnaceText(int32 steelBeamsCount, int32 input1Count, int32 input2Count);
	void UpdateSewingText(int32 sewingMachinesCount, int32 input1Count, int32 input2Count);


	
};
