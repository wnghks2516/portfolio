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

	void SetName(const FString& InName) { Name = InName; }

	int32 GetID() const { return ID; }

	void SetID(int32 InID) { ID = InID; }

	virtual void Serialize(FArchive& Ar) override;



private:
	UPROPERTY()
	FString Name;
	int32 ID;
};
