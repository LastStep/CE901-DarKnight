import pandas as pd
import scipy.stats as stats
import seaborn as sns
import matplotlib.pyplot as plt

# Load the data
data = pd.read_csv('Data/Saved Data - Kartik.csv')

# Clean the data
data.columns = data.columns.str.strip()
data.dropna(subset=['Level Time to Complete', 'Enemies Killed'], inplace=True)
# Convert 'Play Test' to categorical
data['Play Test'] = data['Play Test'].astype('category')

# Check for valid pairings
# Ensure each player or level has corresponding data in both playtests
paired_data = data.groupby(['Hero Name', 'Level Name']).filter(lambda x: len(x) == 2)


# Descriptive Statistics
print("\nDescriptive Statistics by Play Test:")
print(paired_data.groupby('Play Test').describe())



# Visualization for 'Level Time to Complete'
# sns.boxplot(x='Play Test', y='Level Time to Complete', data=paired_data)
# plt.title('Comparison of Level Time to Complete by Play Test')
# plt.xlabel('Play Test')
# plt.ylabel('Time to Complete (minutes)')
# plt.savefig('level_time_to_complete_comparison.png')
# plt.show()

# # Visualization for 'Enemies Killed'
# sns.boxplot(x='Play Test', y='Enemies Killed', data=paired_data)
# plt.title('Comparison of Enemies Killed by Play Test')
# plt.xlabel('Play Test')
# plt.ylabel('Enemies Killed')
# plt.savefig('enemies_killed_comparison.png')
# plt.show()