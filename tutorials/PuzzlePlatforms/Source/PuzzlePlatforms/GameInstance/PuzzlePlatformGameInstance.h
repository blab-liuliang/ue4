// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintPlatformLibrary.h"
#include "PuzzlePlatformGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformGameInstance : public UPlatformGameInstance
{
	GENERATED_BODY()
	
public:
	UPuzzlePlatformGameInstance(const FObjectInitializer& ObjectInitializer);

	// Init
	virtual void Init() override;

public:
	// Host cmd
	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& Address);
};
