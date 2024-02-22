// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerControls.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALCHALLENGE1_API UPlayerControls : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerControls();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere) APawn* Player;
	UPROPERTY(EditAnywhere) float speed = 300.0f;
	bool inputBound = false;

	const FName MOVE_X = FName("MoveX");
	const FName MOVE_Y = FName("MoveY");

	float movementX = 0;
	float movementY = 0;

	bool alongX = false;
	bool alongY = false;

	void MoveX(float axisValue);
	void MoveY(float axisValue);


};
