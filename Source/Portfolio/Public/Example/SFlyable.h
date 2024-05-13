// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SFlyable.generated.h"

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
	//Fly() = 0 -> �߻�޼ҵ��� ��ȣ
	//�������̽������� ������ ���� �ʴ´�.
	virtual void Fly() = 0;
};
