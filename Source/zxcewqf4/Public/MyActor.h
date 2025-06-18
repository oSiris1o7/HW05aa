// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"


#include "Components/StaticMeshComponent.h"

#include "MyActor.generated.h"
UCLASS()
class ZXCEWQF4_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UStaticMeshComponent* staticMeshComponent;

	FVector lastLocation;

	void MoveActorTo(int32 xx, int32 yy);


	int32 GetRandomStep();

	float CalculateDistance(FVector startloca);

	void PerformTenMove();

	void GoRandomStep();

	void RandomEvent();

};


