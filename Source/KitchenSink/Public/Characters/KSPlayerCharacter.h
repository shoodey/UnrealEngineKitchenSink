// Copyright Shoodey. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "KSBaseCharacter.h"
#include "KSPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class KITCHENSINK_API AKSPlayerCharacter : public AKSBaseCharacter
{
	GENERATED_BODY()

public:
	AKSPlayerCharacter();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Camera", meta=(AllowPrivateAccess="true"))
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Camera", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UCameraComponent> FollowCamera;

protected:
	virtual void BeginPlay() override;
};
