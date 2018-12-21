#include "MoveingPlatform.h"

AMoveingPlatform::AMoveingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	// set mobility
	SetMobility(EComponentMobility::Movable);
}

void AMoveingPlatform::BeginPlay()
{
	Super::BeginPlay();

	// only server can be set as Replicates
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}

void AMoveingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// only move on the server
	if (HasAuthority())
	{
		// Move Actor to the x direction every frame
		SetActorLocation(GetActorLocation() + FVector(Speed * DeltaTime, 0, 0));
	}
}