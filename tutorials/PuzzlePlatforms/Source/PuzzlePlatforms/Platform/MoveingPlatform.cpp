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

		GlobalStartLocation = GetActorLocation();
		GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
		CurrentMoveDirection = 1.f;
		ForwardDirectionNormalized = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		TotalLength = (GlobalTargetLocation - GlobalStartLocation).Size();
	}
}

void AMoveingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// only move on the server
	if (ActiveTriggers > 0 && HasAuthority())
	{
		// switch move direction
		float TraveledLength = FVector::DotProduct(GetActorLocation() - GlobalStartLocation, ForwardDirectionNormalized);
		if (TraveledLength > TotalLength && CurrentMoveDirection>0.f)
		{
			CurrentMoveDirection = -1.f;
		}
		else if (TraveledLength < 0.f && CurrentMoveDirection<0.f)
		{
			CurrentMoveDirection = 1.f;
		}

		// update location
		SetActorLocation(GetActorLocation() + Speed * ForwardDirectionNormalized * DeltaTime * CurrentMoveDirection);
	}
}

void AMoveingPlatform::AddActiveTrigger()
{
	ActiveTriggers++;
}

void AMoveingPlatform::RemoveActiveTrigger()
{
	if (ActiveTriggers > 0)
	{
		ActiveTriggers--;
	}
}