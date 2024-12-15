// Copyright Shoodey. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "KSBaseCharacter.h"
#include "KSPlayerCharacter.generated.h"

UCLASS()
class KITCHENSINK_API AKSPlayerCharacter : public AKSBaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AKSPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
