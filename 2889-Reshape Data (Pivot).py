import pandas as pd

def pivotTable(weather: pd.DataFrame) -> pd.DataFrame:
    # index, columns, values
    
    return weather.pivot(index='month', columns='city', values='temperature')