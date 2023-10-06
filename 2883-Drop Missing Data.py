import pandas as pd

def dropMissingData(students: pd.DataFrame) -> pd.DataFrame:
    return students.loc[pd.notna(students['name'])]