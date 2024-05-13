// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PORTFOLIO_API USGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public :
	USGameInstance();

	virtual void Init() override;

	virtual void Shutdown() override;

private:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	TObjectPtr<class USpigeon> SerializedPigeon;
	// Ŭ������ ��� ������ ��Ŭ��� ���� �ʰ�, �ش� Ŭ���� �̸� �տ� class Ű���带 ���� ���� ���漱���̶� ��.
	 // ��� ���Ͽ��� �ٸ� ��� ������ �����ϸ�, �ٸ� ��� ������ �����Ǿ��� �� �� ��� ���ϵ� �Բ� ������ ��.
	 // ���� �� �ʿ��� ��찡 �ƴ϶�� ��� ���Ͽ��� �ٸ� ��������� ��Ŭ��� ���� �ʰ� ���漱���� Ȱ����.
	//���������� �� ���ɼ��� ������.

};
