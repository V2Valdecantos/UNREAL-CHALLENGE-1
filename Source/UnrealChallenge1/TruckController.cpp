// Fill out your copyright notice in the Description page of Project Settings.


#include "TruckController.h"

// Sets default values
ATruckController::ATruckController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATruckController::BeginPlay()
{
	Super::BeginPlay();
	this->Truck1->isActive = true;
	this->Truck2->isActive = true;
	
}

// Called every frame
void ATruckController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	fTicks += DeltaTime;

}

void ATruckController::SetDestination(ATruck* truck, EBuildingType currentLocation, EBuildingType destination)
{
	ASpline* nextPath = nullptr;
	

	switch (currentLocation)
	{
		case EBuildingType::COAL_MINE:
				if (destination == EBuildingType::FURNACE)
				{
					nextPath = this->coalMineSplines[2];
				} else if (destination == EBuildingType::LUMBER_YARD)
				{
					nextPath = this->coalMineSplines[1];

				} else if (destination == EBuildingType::IRON_MINE)
				{
					nextPath = this->coalMineSplines[0];
				}

				if (nextPath != nullptr) 
				{
					truck->currentPath = nextPath;
					truck->ResetSpline();
				}

				break;

		case EBuildingType::IRON_MINE:
			if (destination == EBuildingType::FURNACE)
			{
				nextPath = this->ironMineSplines[2];
			}
			else if (destination == EBuildingType::LUMBER_YARD)
			{
				nextPath = this->ironMineSplines[1];

			}
			else if (destination == EBuildingType::COAL_MINE)
			{
				nextPath = this->ironMineSplines[0];
			}

			if (nextPath != nullptr)
			{
				truck->currentPath = nextPath;
				truck->ResetSpline();
			}

			break;

		case EBuildingType::FURNACE:
			if (destination == EBuildingType::FACTORY)
			{
				nextPath = this->furnaceSplines[3];
			}
			else if (destination == EBuildingType::LUMBER_YARD)
			{
				nextPath = this->furnaceSplines[2];

			}
			else if (destination == EBuildingType::IRON_MINE)
			{
				nextPath = this->furnaceSplines[1];
			}
			else if (destination == EBuildingType::COAL_MINE)
			{
				nextPath = this->furnaceSplines[0];
			}

			if (nextPath != nullptr)
			{
				truck->currentPath = nextPath;
				truck->ResetSpline();
			}

			break;

		case EBuildingType::LUMBER_YARD:
			if (destination == EBuildingType::FACTORY)
			{
				nextPath = this->lumberSplines[2];
			}
			else if (destination == EBuildingType::IRON_MINE)
			{
				nextPath = this->lumberSplines[1];

			}
			else if (destination == EBuildingType::COAL_MINE)
			{
				nextPath = this->lumberSplines[0];
			}

			if (nextPath != nullptr)
			{
				truck->currentPath = nextPath;
				truck->ResetSpline();
			}

			break;

		case EBuildingType::FACTORY:
			if (destination == EBuildingType::LUMBER_YARD)
			{
				nextPath = this->sewingSplines[3];
			}
			else if (destination == EBuildingType::FURNACE)
			{
				nextPath = this->sewingSplines[2];

			}
			else if (destination == EBuildingType::IRON_MINE)
			{
				nextPath = this->sewingSplines[1];
			}
			else if (destination == EBuildingType::COAL_MINE)
			{
				nextPath = this->sewingSplines[0];
			}

			if (nextPath != nullptr)
			{
				truck->currentPath = nextPath;
				truck->ResetSpline();
			}

			break;
	}
}

