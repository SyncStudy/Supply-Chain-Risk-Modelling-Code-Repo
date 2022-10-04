import pandas as pd
import plotly
import plotly.express as px

import dash
from dash import dcc
from dash import html
from dash.dependencies import Input, Output
from dash.exceptions import PreventUpdate
# "pip install alpha_vantage" (if you haven't done so)
from alpha_vantage.timeseries import TimeSeries
from alpha_vantage.cryptocurrencies import CryptoCurrencies
from alpha_vantage.foreignexchange import ForeignExchange
#-------------------------------------------------------------------------------
# Set up initial key and financial category

key = '52GI58AJW3MOZUFL' # Your API Key
# https://github.com/RomelTorres/alpha_vantage
# Chose your output format or default to JSON (python dict)
ts = TimeSeries(key, output_format='pandas') # 'pandas' or 'json' or 'csv'
cc = CryptoCurrencies(key,output_format='pandas')
fx = ForeignExchange(key,output_format='pandas')
#-------------------------------------------------------------------------------
# (only for example purposes) Pull data from API and prepare it for plotting on line chart

# Get the data, returns a tuple
# IBM_data is a pandas dataframe, IBM_meta_data is a dict
# https://github.com/RomelTorres/alpha_vantage/blob/develop/alpha_vantage/timeseries.py
# IBM_data, IBM_meta_data = ts.get_daily(symbol='IBM', outputsize='compact')
BTC_data, BTC_meta_data = cc.get_digital_currency_weekly(symbol='BTC', market='USD')
USD_CNY_fx, USD_CNY_meta_data = fx.get_currency_exchange_daily(from_symbol='USD', to_symbol='CNY', outputsize='compact')

# print(IBM_meta_data)
# print(BTC_meta_data)

df = BTC_data.copy()
df.to_csv('out.csv', index=False)
df1 = USD_CNY_fx.copy()
df1.to_csv('out1.csv', index=False)
# df2 = USD_CNY_fx.copy()
# df2.to_csv('out2.csv', index=False)

# print(df.head())
# print(df1.head())

df = df.transpose()
df1 = df1.transpose()
# df2 = df2.transpose()

# print(df.head())
# print(df1.transpose())

df1.rename(index={"1. open": "open", "2. high": "high", "3. low": "low",
                     "4. close": "close", "5. volume": "volume"}, inplace=True)
df.rename(index={"1a. open (USD)": "open (USD)", "1b. open (USD)": "open (USD)", "2a. high (USD)": "high (USD)",
                      "2b. high (USD)": "high (USD)", "3a. low (USD)": "low (USD)", "3b. low (USD)": "low (USD)",
                      "4a. close (USD)": "close (USD)", "4b. close (USD)": "close (USD)", "5. volume": "volume",
                      "6. market cap (USD)": "market cap (USD)"}, inplace=True)
# df2.rename(index={"1. open": "open","2. high":"high","3. low":"low","4. close":"close"}, inplace=True)

df = df.reset_index().rename(columns={'index': 'indicator'})
df1 = df1.reset_index().rename(columns={'index': 'indicator'})
# df2 = df2.reset_index().rename(columns={'index': 'indicator'})

# print(df.head())
# print(df1.head())

df = pd.melt(df, id_vars=['indicator'], var_name='date', value_name='rate')
df1 = pd.melt(df1, id_vars=['indicator'], var_name='date', value_name='rate')#？
# df2 = pd.melt(df2, id_vars=['indicator'], var_name='date', value_name='rate')#？

df = df[df['indicator'] != 'volume']
df = df[df['indicator'] != 'market cap (USD)']
df1 = df1[df1['indicator'] != 'volume']

# df2 = df2[df2['indicator'] != 'volume']

# print(df[:15])
# print(df1[:15])
#-------------------------------------------------------------------------------

# df = pd.DataFrame({
#     "Fruit": ["Apples", "Oranges", "Bananas", "Apples", "Oranges", "Bananas"],
#     "Amount": [4, 1, 2, 2, 4, 5],
#     "City": ["SF", "SF", "SF", "Montreal", "Montreal", "Montreal"]
# })
line_chart = px.line(
                    data_frame=df,
                    x='date',
                    y='rate',
                    color='indicator',
                    # title="Stock: {}".format(IBM_meta_data['2. Symbol'])
                    title="Bitcoin Price"
                 )
fig = px.line(data_frame=df1,
                    x='date',
                    y='rate',
                    color='indicator',
                    # title="Stock: {}".format(IBM_meta_data['2. Symbol'])
                    title="US-CNY Exchange Rate"
                 )
# fig1 = px.line(data_frame=df2,
#                     x='date',
#                     y='rate',
#                     color='indicator',
#                     # title="Stock: {}".format(IBM_meta_data['2. Symbol'])
#                     title="US-CNY"
#                  )

#-------------------------------------------------------------------------------
# Building our Web app and update financial data automatically

app = dash.Dash(__name__)
colors = {
    'background': '#111111',
    'text': '#7FDBFF'
}
app.layout = html.Div([

    html.H1(children='CSI300 Index Option Indicator Dashboard',style={
            'textAlign': 'center',
            'color': colors['text']
        }),
    html.Div(children='An indicator dashboard for CSI300 Index Option', style={
        'textAlign': 'center',
        'color': colors['text']
    }),
    # dcc.Interval(
    #             id='my_interval',
    #             n_intervals=0,       # number of times the interval was activated
    #             interval=120*10000000,   # update every 2 minutes
    # ),
    # dcc.Graph(id="world_finance"),   # empty graph to be populated by line chart
    dcc.Graph(
        id='example-graph1',
        figure=fig
    ),

    dcc.Graph(
        id='example-graph2',
        figure=line_chart
    ),
    # dcc.Graph(
    #     id='example-graph3',
    #     figure=fig1
    # )
    #dcc.Graph(id="world_finance1"),
])

#-------------------------------------------------------------------------------,
# @app.callback(
#     Output(component_id='world_finance', component_property='figure'),
#     #Output(component_id='world_finance1', component_property='figure'),
#     [Input(component_id='my_interval', component_property='n_intervals')]
# )


# def update_graph(n):
#     """Pull financial data from Alpha Vantage and update graph every 2 minutes"""
#     # IBM_data, IBM_meta_data = ts.get_daily(symbol='IBM', outputsize='compact')
#     BTC_data, BTC_meta_data = cc.get_digital_currency_daily(symbol='BTC', market='USD')
#
#     # print(IBM_meta_data)
#     print(BTC_meta_data)
#
#     # df = IBM_data.copy()
#     # df.to_csv('out.csv', index=False)
#     df1 = BTC_data.copy()
#     df1.to_csv('out1.csv', index=False)
#
#     # print(df.head())
#     print(df1.head())
#
#     # df = df.transpose()
#     df1 = df1.transpose()
#
#     # print(df.head())
#     print(df1.transpose())
#
#     # df.rename(index={"1. open": "open", "2. high": "high", "3. low": "low",
#     #                      "4. close": "close", "5. volume": "volume"}, inplace=True)
#     df1.rename(index={"1a. open (CNY)": "open (CNY)", "1b. open (USD)": "open (USD)", "2a. high (CNY)": "high (CNY)",
#                       "2b. high (USD)": "high (USD)", "3a. low (CNY)": "low (CNY)", "3b. low (USD)": "low (USD)",
#                       "4a. close (CNY)": "close (CNY)", "4b. close (USD)": "close (USD)", "5. volume": "volume",
#                       "6. market cap (USD)": "market cap (USD)"}, inplace=True)
#
#     # df = df.reset_index().rename(columns={'index': 'indicator'})
#     df1 = df1.reset_index().rename(columns={'index': 'indicator'})
#
#     # print(df.head())
#     print(df1.head())
#
#     # df = pd.melt(df, id_vars=['indicator'], var_name='date', value_name='rate')
#     df1 = pd.melt(df1, id_vars=['indicator'], var_name='date', value_name='rate')
#
#     # df = df[df['indicator'] != 'volume']
#     df1 = df1[df1['indicator'] != 'volume']
#
#     # print(df[:15])
#     print(df1[:15])
#

#     # line_chart1 = px.line(
#     #     data_frame=df1,
#     #     x='date',
#     #     y='rate',
#     #     color='indicator',
#     #     title="Crypto: Bitcoin"
#     # )
#     return line_chart

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    app.run_server(debug=True)
