// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Buidling.h"
#include "LumberYard.generated.h"

UCLASS()
class UNREALCHALLENGE1_API ALumberYard : public ABuilding
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALumberYard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void StartProduction() override;
	virtual void StopProduction() override;

	virtual void LoadMaterials(ATruck* truck) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
	UFUNCTION()
	void EndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
