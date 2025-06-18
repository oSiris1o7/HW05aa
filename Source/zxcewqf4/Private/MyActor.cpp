// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	//lastLocation = GetActorLocation();

	FVector actorStartLocation = FVector(0, 0, 0);
	SetActorLocation(actorStartLocation);

	PerformTenMove();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
}


void AMyActor::MoveActorTo(int32 xx, int32 yy)
{
	lastLocation = GetActorLocation();
	FVector newLocation = FVector(lastLocation.X + xx, lastLocation.Y + yy, GetActorLocation().Z);
	SetActorLocation(newLocation);


	int a = newLocation.X;
	int b = newLocation.Y;

	UE_LOG(LogTemp, Log, TEXT("%d, %d 로 이동"), (int)newLocation.X, (int)newLocation.Y);

	//UE_LOG(LogTemp, Log, TEXT("액터가 이동하여 현재 위치: %s"), *GetActorLocation().ToString());


}


int32 AMyActor::GetRandomStep()
{
	return FMath::RandRange(0, 1);
}

float AMyActor::CalculateDistance(FVector startloca)
{
	return FVector::Distance(startloca, GetActorLocation());
}

void AMyActor::GoRandomStep()
{
	int a = 0;
	int b = 0;
	while (a == 0 && b == 0)
	{
		a = GetRandomStep();
		b = GetRandomStep();
	}
	

	MoveActorTo(a, b);
}



void AMyActor::PerformTenMove()
{
	FVector startLocation = GetActorLocation();

	for (int i = 0; i < 10; i++)
	{
		GoRandomStep();
		RandomEvent();
	}

	float moveDistance = CalculateDistance(startLocation);
	
	UE_LOG(LogTemp, Log, TEXT("10회 이동 거리 = %f"), moveDistance);
}


void AMyActor::RandomEvent()
{
	if (FMath::RandRange(0, 1) == 0)
	{
		UE_LOG(LogTemp, Log, TEXT("이벤트 발생"));
	}
}


