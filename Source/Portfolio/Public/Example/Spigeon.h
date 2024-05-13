// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SFlyable.h"
#include "Spigeon.generated.h"

/**
 * 
 */
UCLASS()
class PORTFOLIO_API USpigeon : public UObject , public ISFlyable
{
	GENERATED_BODY()
	
public:
	USpigeon();

	virtual void Fly() override;

private:
	UPROPERTY()
	FString name;

};
