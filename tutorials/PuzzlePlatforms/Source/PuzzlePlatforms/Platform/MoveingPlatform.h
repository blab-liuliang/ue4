#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MoveingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMoveingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMoveingPlatform();

	// Begin Play
	virtual void BeginPlay() override;

	// Tick
	virtual void Tick(float DeltaTime) override;

	// Trigger operate
	void AddActiveTrigger();
	void RemoveActiveTrigger();

public:
	UPROPERTY(EditAnywhere)
	float	Speed = 20;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;

	UPROPERTY(EditAnywhere)
	int		 ActiveTriggers = 1;

private:
	FVector  GlobalStartLocation;
	FVector  GlobalTargetLocation;
	FVector  ForwardDirectionNormalized;
	float    TotalLength;
	float	 CurrentMoveDirection;
};
