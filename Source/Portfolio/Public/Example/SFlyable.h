// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SFlyable.generated.h"

USTRUCT()
struct FBirdData
{
    GENERATED_BODY()

public:
    FBirdData() {}

    FBirdData(const FString& InName, int32 InID)
        : Name(InName)
        , ID(InID)
    {
    }

    friend FArchive& operator<<(FArchive& Ar, FBirdData& InBirdData)
    {
        Ar << InBirdData.Name;
        Ar << InBirdData.ID;
        return Ar;
    }

    UPROPERTY()
    FString Name = TEXT("DefaultBirdName");

    UPROPERTY()
    int32 ID = 0;

};


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USFlyable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PORTFOLIO_API ISFlyable
{
	GENERATED_BODY()
	
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//Fly() = 0 -> 추상메소드의 기호
	//인터페이스에서는 구현을 하지 않는다.
	virtual void Fly() = 0;
};
