import re
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import warnings
import math
from sklearn import linear_model
train_data = pd.read_csv('train.csv')
test_data = pd.read_csv('test.csv')
sns.set_style('whitegrid')
combine=train_data.append(test_data)
combine=combine[['TotalBsmtSF','1stFlrSF','LotShape','OverallQual','GrLivArea','GarageCars','GarageArea','SalePrice' ]]
combine['shape']=pd.factorize(combine['LotShape'])[0]
shape_df=pd.get_dummies(combine['shape'],prefix='shape')
combine=pd.concat([combine,shape_df],axis=1)
combine.drop(['shape'],axis=1,inplace=True)
combine.drop(['LotShape'],axis=1,inplace=True)
combine['TotalBsmtSF'].fillna(combine['TotalBsmtSF'].mode().iloc[0],inplace=True)
combine['GarageCars'].fillna(combine['GarageCars'].mode().iloc[0],inplace=True)
combine['GarageArea'].fillna(combine['GarageArea'].mode().iloc[0],inplace=True)
train=combine[:1460]
test=combine[1460:]
train_data_X=train.drop(['SalePrice'],axis=1)
train_data_Y=train['SalePrice']
test_data_X=test.drop(['SalePrice'],axis=1)
def cost(x,y,lam,theta):
    m,n=x.values.shape
    a=x.dot(theta)-y
    b=(a.dot(a.T))/(2*m)
    cost=b+lam*(np.sum(np.abs(theta)))
    return cost
def gettheta(x,y,lam,theta,a):
    m,n=x.values.shape
    for j in range(1,n+1):
        for i in range(1,100000):
            COST=cost(x,y,lam,theta)
            theta[j-1]=theta[j-1]+a
            COST2=cost(x,y,lam,theta)
            if COST2>COST:
                theta[j-1]=theta[j-1]-2*a
            if abs(COST-COST2)<0.01:
                print(j,i)
                break
    print(theta)
k=30
lam=1
m,n=train_data_X.values.shape
theta=np.ones(n)
gettheta(train_data_X,train_data_Y,1,theta,10)