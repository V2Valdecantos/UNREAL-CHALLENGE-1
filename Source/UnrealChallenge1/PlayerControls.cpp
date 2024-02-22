// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControls.h"

// Sets default values for this component's properties
UPlayerControls::UPlayerControls()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerControls::BeginPlay()
{
	Super::BeginPlay();
	if (this->Player != NULL) {
		if (this->Player->InputComponent != NULL)
		{
			this->Player->InputComponent->BindAxis(MOVE_X, this, &UPlayerControls::MoveX);
			this->Player->InputComponent->BindAxis(MOVE_Y, this, &UPlayerControls::MoveY);

			this->inputBound = true;
		}
	}


	// ...
	
}


// Called every frame
void UPlayerControls::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (this->Player != NULL) {

		if (!this->inputBound)
		{
			if (this->Player->InputComponent != NULL)
			{
				this->Player->InputComponent->BindAxis(MOVE_X, this, &UPlayerControls::MoveX);
				this->Player->InputComponent->BindAxis(MOVE_Y, this, &UPlayerControls::MoveY);

				this->inputBound = true;
			}
		}

		if (this->alongX)
		{
			FVector location = this->Player->GetTransform().GetLocation();
			location.X += this->movementX * DeltaTime * this->speed;
			this->Player->SetActorLocation(location);
		}

		if (this->alongY)
		{
			FVector location = this->Player->GetTransform().GetLocation();
			location.Y += this->movementY * DeltaTime * this->speed;
			this->Player->SetActorLocation(location);
		}
	}
	// ...
}
 
void UPlayerControls::MoveX(float axisValue)
{
	//UE_LOG(LogTemp, Display, TEXT("Moving along X: %f", axisValue));
	this->movementX = FMath::Clamp(axisValue, -1.0f, 1.0f);
	if (this->movementX != 0)
	{
		this->alongX = true;
	}
}

void UPlayerControls::MoveY(float axisValue)
{
	//UE_LOG(LogTemp, Display, TEXT("Moving along Y: %f", axisValue));
	this->movementY = FMath::Clamp(axisValue, -1.0f, 1.0f);
	if (this->movementY != 0)
	{
		this->alongY = true;
	}
}
