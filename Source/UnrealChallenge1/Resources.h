// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Resources.generated.h"

UCLASS()
class UNREALCHALLENGE1_API AResources : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AResources();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int count = 0;

};
//
//UCLASS()
//class ACoal : public AResources
//{
//	GENERATED_BODY()
//
//public:
//
//	ACoal();
//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//
//public:
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
//
//	
//};
//
//UCLASS()
//class AWood : public AResources
//{
//	GENERATED_BODY()
//
//public:
//
//	AWood();
//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//
//public:
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
//
//};
//
//UCLASS()
//class AIron : public AResources
//{
//	GENERATED_BODY()
//
//public:
//
//	AIron();
//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//
//public:
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
//
//
//};
//
//UCLASS()
//class ASteelBeam : public AResources
//{
//	GENERATED_BODY()
//
//public:
//
//	ASteelBeam();
//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//
//public:
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
//
//};
//
//UCLASS()
//class ASewingMachine : public AResources
//{
//	GENERATED_BODY()
//
//public:
//
//	ASewingMachine();
//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//
//public:
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
//
//};

