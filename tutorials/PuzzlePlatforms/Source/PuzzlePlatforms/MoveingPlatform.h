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

	// Tick
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere)
	float	Speed = 20;
};
