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

public:
	UPROPERTY(EditAnywhere)
	float	Speed = 20;
};
