import pandas as pd

def fillMissingValues(products: pd.DataFrame) -> pd.DataFrame:
# The fillna() method returns a new DataFrame object unless the inplace parameter is set to True    

# Method 1
    products['quantity'].fillna(0, inplace=True)
    return products

# Method 2
    values = {"quantity": 0}
    products.fillna(value=values, inplace=True)

    return products