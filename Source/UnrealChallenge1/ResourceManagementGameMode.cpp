// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceManagementGameMode.h"

void AResourceManagementGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (gameWidgetClass)
	{
		gameWidget = Cast<UGameWidget>(CreateWidget(GetWorld(), gameWidgetClass));

		if (gameWidget)
		{
			gameWidget->AddToViewport();
			this->UpdateText();
		}
	}
}

void AResourceManagementGameMode::UpdateText()
{
}

void AResourceManagementGameMode::UpdateCoalMineText(int32 coalCount)
{
	this->coal = coalCount;
	this->gameWidget->coal = coalCount;
}

void AResourceManagementGameMode::UpdateIronMineText(int32 ironCount)
{
	this->iron = ironCount;
	this->gameWidget->iron = ironCount;
}

void AResourceManagementGameMode::UpdateLumberYardText(int32 woodCount)
{
	this->wood = woodCount;
	this->gameWidget->wood = woodCount;

}

void AResourceManagementGameMode::UpdateFurnaceText(int32 steelBeamsCount, int32 input1Count, int32 input2Count)
{
	this->steelBeams = steelBeamsCount;
	this->furnaceInput1 = input1Count;
	this->furnaceInput2 = input2Count;
	this->gameWidget->steelBeams = steelBeamsCount;
	this->gameWidget->furnaceInput1 = input1Count;
	this->gameWidget->furnaceInput2 = input2Count;
}

void AResourceManagementGameMode::UpdateSewingText(int32 sewingMachinesCount, int32 input1Count, int32 input2Count)
{
	this->sewingMachines = sewingMachinesCount;
	this->sewingInput1 = input1Count;
	this->sewingInput2 = input2Count;
	this->gameWidget->sewingMachines = sewingMachinesCount;
	this->gameWidget->sewingInput1 = input1Count;
	this->gameWidget->sewingInput2 = input2Count;
}
