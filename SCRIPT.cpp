{\rtf1\ansi\ansicpg1252\cocoartf2638
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fmodern\fcharset0 CourierNewPSMT;\f1\fnil\fcharset0 Menlo-Regular;\f2\fnil\fcharset134 PingFangSC-Regular;
}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;\red115\green138\blue4;\red252\green244\blue220;
\red71\green91\blue98;\red19\green118\blue70;\red129\green144\blue144;}
{\*\expandedcolortbl;;\cssrgb\c0\c0\c0;\cssrgb\c52157\c60000\c0;\cssrgb\c99216\c96471\c89020;
\cssrgb\c34510\c43137\c45882;\cssrgb\c3529\c52549\c34510;\cssrgb\c57647\c63137\c63137;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\partightenfactor0

\f0\fs27\fsmilli13600 \cf0 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 \
\
\pard\pardeftab720\partightenfactor0
\cf3 \cb4 \strokec3 #include\cf0 \strokec2  \cf3 \strokec3 <\cf5 \strokec5 math.h\cf3 \strokec3 >\cf0 \cb1 \strokec2 \
\cf3 \cb4 \strokec3 #include\cf0 \strokec2  \cf3 \strokec3 <\cf5 \strokec5 stdint.h\cf3 \strokec3 >\cf0 \cb1 \strokec2 \
\cf3 \cb4 \strokec3 #include\cf0 \strokec2  \cf3 \strokec3 <\cf5 \strokec5 stdio.h\cf3 \strokec3 >\cf0 \cb1 \strokec2 \
\cf3 \cb4 \strokec3 #include\cf0 \strokec2  \cf3 \strokec3 <\cf5 \strokec5 uncertain.h\cf3 \strokec3 >\cf0 \cb1 \strokec2 \
\cf3 \cb4 \strokec3 #include\cf0 \strokec2  \cf3 \strokec3 <\cf5 \strokec5 stddef.h\cf3 \strokec3 >\cf0 \cb1 \strokec2 \
\cf3 \cb4 \strokec3 #include\cf0 \strokec2  \cf3 \strokec3 <\cf5 \strokec5 uncertain.h\cf3 \strokec3 >\cf0 \cb1 \strokec2 \
\
\
\cf3 \cb4 \strokec3 static\cf0 \strokec2  \cf3 \strokec3 void\cf0 \cb1 \strokec2 \
\pard\pardeftab720\partightenfactor0
\cf0 \cb4 loadInputs(\cf3 \strokec3 double\cf0 \strokec2  *  G, \cf3 \strokec3 double\cf0 \strokec2  *  M, \cf3 \strokec3 double\cf0 \strokec2  *  Rs, \cf3 \strokec3 double\cf0 \strokec2  *  b, \cf3 \strokec3 double\cf0 \strokec2  *  gamma, \cf3 \strokec3 double\cf0 \strokec2  *  phi)\cb1 \
\cb4 \{\cb1 \
\cb4     \cf3 \strokec3 double\cf0 \strokec2  empiricalTaylorFactorValues[] = \{\cb1 \
\cb4                         \cf6 \strokec6 3.2\cf0 \strokec2 ,\cb1 \
\cb4                         \cf6 \strokec6 3.9\cf0 \strokec2 ,\cb1 \
\cb4                         \cf6 \strokec6 4.1\cf0 \strokec2 ,\cb1 \
\cb4                         \cf6 \strokec6 3.2\cf0 \strokec2 ,\cb1 \
\cb4                         \cf6 \strokec6 3.8\cf0 \strokec2 ,\cb1 \
\cb4                         \cf6 \strokec6 3.8\cf0 \strokec2 ,\cb1 \
\cb4                         \cf6 \strokec6 2.1\cf0 \strokec2 ,\cb1 \
\cb4                         \cf6 \strokec6 3.0\cf0 \strokec2 ,\cb1 \
\cb4                         \cf6 \strokec6 1.9\cf0 \strokec2 ,\cb1 \
\cb4                         \cf6 \strokec6 3.9\cf0 \strokec2 ,\cb1 \
\cb4                         \cf6 \strokec6 2.3\cf0 \strokec2 ,\cb1 \
\cb4                         \cf6 \strokec6 2.2\cf0 \strokec2 ,\cb1 \
\cb4                         \cf6 \strokec6 3.2\cf0 \strokec2 ,\cb1 \
\cb4                         \cf6 \strokec6 2.2\cf0 \strokec2 ,\cb1 \
\cb4                         \cf6 \strokec6 3.9\cf0 \strokec2 ,\cb1 \
\cb4                         \cf6 \strokec6 2.2\cf0 \strokec2 ,\cb1 \
\cb4                         \cf6 \strokec6 1.9\cf0 \strokec2 ,\cb1 \
\cb4                         \cf6 \strokec6 3.2\cf0 \strokec2 ,\cb1 \
\cb4                         \cf6 \strokec6 3.9\cf0 \strokec2 ,\cb1 \
\cb4                         \cf6 \strokec6 3.1\cf0 \strokec2 ,\cb1 \
\cb4                     \};\cb1 \
\
\cb4     *M      = libUncertainDoubleDistFromSamples(\cb1 \
\cb4                                 empiricalTaylorFactorValues,\cb1 \
\cb4                                 \cf3 \strokec3 sizeof\cf0 \strokec2 (empiricalTaylorFactorValues)/\cf3 \strokec3 sizeof\cf0 \strokec2 (\cf3 \strokec3 double\cf0 \strokec2 )\cb1 \
\cb4                             );\cb1 \
\cb4     *G      = \cf6 \strokec6 7E10\cf0 \strokec2 ;\cb1 \
\cb4     *Rs     = \cf6 \strokec6 2E-8\cf0 \strokec2 ;\cb1 \
\cb4     *b      = \cf6 \strokec6 2.54E-10\cf0 \strokec2 ;\cb1 \
\cb4     *gamma  = \cf6 \strokec6 0.2\cf0 \strokec2 ;\cb1 \
\cb4     *phi    = \cf6 \strokec6 0.375\cf0 \strokec2 ;\cb1 \
\cb4 \}\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf3 \cb4 \strokec3 int\cf0 \cb1 \strokec2 \
\pard\pardeftab720\partightenfactor0
\cf0 \cb4 main(\cf3 \strokec3 int\cf0 \strokec2  argc, \cf3 \strokec3 char\cf0 \strokec2  *   argv[])\cb1 \
\cb4 \{\cb1 \
\cb4     \cf3 \strokec3 double\cf0 \strokec2   G, M, Rs, b, gamma, phi, sigmaC;\cb1 \
\
\
\cb4     loadInputs(&G, &M, &Rs, &b, &gamma, &phi);\cb1 \
\
\cb4     \cf7 \strokec7 /*\cf0 \cb1 \strokec2 \
\pard\pardeftab720\partightenfactor0
\cf7 \cb4 \strokec7      *                    
\f1 \uc0\u9115 
\f0     _________________    
\f1 \uc0\u9118 
\f0 \cf0 \cb1 \strokec2 \
\cf7 \cb4 \strokec7      *       
\f1 \uc0\u9115 
\f0  M 
\f1 \uc0\u8901 
\f0  \uc0\u947   
\f1 \uc0\u9118 
\f0    
\f1 \uc0\u9116 
\f0    
\f1 \uc0\u9585 
\f0 8.0 
\f1 \uc0\u8901 
\f0  \uc0\u947  
\f1 \uc0\u8901 
\f0  \uc0\u966  
\f1 \uc0\u8901 
\f0  Rs     
\f1 \uc0\u9119 
\f0 \cf0 \cb1 \strokec2 \
\cf7 \cb4 \strokec7      *  \uc0\u963   = 
\f1 \uc0\u9116 
\f0 \uc0\u9472 \u9472 \u9472 \u9472 \u9472 \u9472 \u9472  
\f1 \uc0\u9119 
\f0  
\f1 \uc0\u8901 
\f0  
\f1 \uc0\u9116 
\f0   
\f1 \uc0\u9585 
\f0  \uc0\u9472 \u9472 \u9472 \u9472 \u9472 \u9472 \u9472 \u9472 \u9472 \u9472 \u9472 \u9472 \u9472 \u9472 \u9472 \u9472 \u9472  - \u966 
\f1 \uc0\u9119 
\f0 \cf0 \cb1 \strokec2 \
\cf7 \cb4 \strokec7      *   c   
\f1 \uc0\u9117 
\f0 2.0 
\f1 \uc0\u8901 
\f0  b 
\f1 \uc0\u9120 
\f0    
\f1 \uc0\u9117 \u9586 \u9585 
\f0   \uc0\u960  
\f1 \uc0\u8901 
\f0  G 
\f1 \uc0\u8901 
\f0  pow(b, 2)    
\f1 \uc0\u9120 
\f0 \cf0 \cb1 \strokec2 \
\cf7 \cb4 \strokec7      */\cf0 \cb1 \strokec2 \
\pard\pardeftab720\partightenfactor0
\cf0 \cb4     sigmaC = (\cf6 \strokec6 100\cf0 \strokec2 -M)/\cf6 \strokec6 100\cf0 \strokec2 ;\cb1 \
\
\
\pard\pardeftab720\partightenfactor0
\cf7 \cb4 \strokec7 //     Perfect Order Measurement = [(Total orders \'96 Error orders) / Total orders] \'d7 100\cf0 \cb1 \strokec2 \
\
\cf7 \cb4 \strokec7 // This metric is important as it calculates the percentage of orders that are free from errors.  It calculates the rate of error-free delivery for each stage of a purchase order. These errors can be in the form of procurement forecasting error, warehouse pickup processing error, invoicing error, shipping order errors, etc. It can be broken down stage-wise as:\cf0 \cb1 \strokec2 \
\
\cf7 \cb4 \strokec7 // 99.98 percent perfect for warehousing\cf0 \cb1 \strokec2 \
\cf7 \cb4 \strokec7 // 99.02 percent perfect for transportation\cf0 \cb1 \strokec2 \
\cf7 \cb4 \strokec7 // 99.12 percent perfect for production\cf0 \cb1 \strokec2 \
\cf7 \cb4 \strokec7 // 99.99 percent perfect for procurement\cf0 \cb1 \strokec2 \
\pard\pardeftab720\partightenfactor0
\cf0 \cb4     \cf7 \strokec7 //printf(" %d \\n", sigmaC);\cf0 \cb1 \strokec2 \
\
\cb4     printf(\cf5 \strokec5 "Perfect Order Measurement is\\t\\t= %.1E  \\n"\cf0 \strokec2 , sigmaC);\cb1 \
\
\cb4     libUncertainDoublePrint(sigmaC);\cb1 \
\
\
\pard\pardeftab720\partightenfactor0
\cf7 \cb4 \strokec7 // Inventory Turnover Ratio (ITR) = Cost of Goods/ [(Opening Stock \'96 Closing Stock) / 2]\cf0 \cb1 \strokec2 \
\
\cf7 \cb4 \strokec7 // The Inventory Turnover ratio helps determine the number of times a company sells or turns the average inventory that is kept in the storehouses. Therefore, in other words, it is a measure of opportunities to make profits from the working capital that is invested in the form of inventory.\cf0 \cb1 \strokec2 \
\
\
\
\cf7 \cb4 \strokec7 //Inventory Turnover Ratio (ITR) = Cost of Goods/ [(Opening Stock \'96 Closing Stock) / 2]\cf0 \cb1 \strokec2 \
\
\
\
\
\pard\pardeftab720\partightenfactor0
\cf0 \cb4     \cf3 \strokec3 double\cf0 \strokec2  inventoryTurnOverRate;\cb1 \
\cb4     \cf3 \strokec3 double\cf0 \strokec2  costOfGoods=\cf6 \strokec6 100\cf0 \strokec2 ;\cb1 \
\cb4     \cf3 \strokec3 double\cf0 \strokec2  openStock = \cf6 \strokec6 100\cf0 \strokec2 ;\cb1 \
\
\cb4     inventoryTurnOverRate = \cf6 \strokec6 30\cf0 \strokec2  / ((\cf6 \strokec6 100\cf0 \strokec2 -M)/\cf6 \strokec6 2\cf0 \strokec2 );\cb1 \
\
\cb4     \cf7 \strokec7 //printf("Inventory Turnover Ratio \\n");\cf0 \cb1 \strokec2 \
\
\cb4     printf(\cf5 \strokec5 "Inventory Turnover Ratio \\t\\t= %.1E  \\n"\cf0 \strokec2 , inventoryTurnOverRate);\cb1 \
\
\
\cb4     libUncertainDoublePrint(inventoryTurnOverRate);\cb1 \
\
\
\pard\pardeftab720\partightenfactor0
\cf7 \cb4 \strokec7 // Cash to Cash Cycle Time\cf0 \cb1 \strokec2 \
\cf7 \cb4 \strokec7 // Cash to Cash Cycle Time = Materials payment date \'96 Customer order payment date\cf0 \cb1 \strokec2 \
\
\cf7 \cb4 \strokec7 // This ratio measures the number of days between the payment of materials to the getting the payment for the product. It is averaged on a weekly, monthly or quarterly basis. The ratio tells of the amount of time the operating capital is tied up for and it is important from the point of view that cash tied up is unavailable for use for other purposes. A smooth cash to cash operation denotes a supply chain that is profitable.\cf0 \cb1 \strokec2 \
\
\
\
\
\
\
\pard\pardeftab720\partightenfactor0
\cf0 \cb4    \cb1 \
\
\cb4     \cf3 \strokec3 double\cf0 \strokec2  Materials_payment_date = \cf6 \strokec6 8\cf0 \strokec2 ;\cb1 \
\cb4     \cf3 \strokec3 double\cf0 \strokec2  Customer_order_payment_date=M;\cb1 \
\cb4     \cf3 \strokec3 double\cf0 \strokec2  Cash_to_Cash_Cycle_Time=Materials_payment_date-Customer_order_payment_date;\cb1 \
\
\cb4      printf(\cf5 \strokec5 "Cash to Cash Cycle Time is\\t\\t= %.1E  \\n"\cf0 \strokec2 , Cash_to_Cash_Cycle_Time);\cb1 \
\cb4     libUncertainDoublePrint(Cash_to_Cash_Cycle_Time);\cb1 \
\cb4     \cb1 \
\cb4     \cf7 \strokec7 //printf("Alloy strength (\uc0\u963 c)\\t\\t= %.1E MPa\\n", sigmaC/1000000);\cf0 \cb1 \strokec2 \
\cb4     \cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf7 \cb4 \strokec7 // Days of Supply = [Average inventory on hand (as value) / Average monthly demand (as value)] \'d7 30 (for measurement on a monthly basis)\cf0 \cb1 \strokec2 \
\
\cf7 \cb4 \strokec7 // This forms one of the key performance indicators that measure the efficiency in supply chain.\cf0 \cb1 \strokec2 \
\
\
\cf7 \cb4 \strokec7 //printf("Days of Supply \\n");\cf0 \cb1 \strokec2 \
\
\cf7 \cb4 \strokec7 //
\f2 \'c8\'e7\'b9\'fb\'cf\'fa\'ca\'db\'bc\'cc\'d0\'f8\'d2\'d4\'d3\'eb\'bd\'fc\'c6\'da\'cf\'fa\'ca\'db\'cf\'e0\'cd\'ac\'b5\'c4\'cb\'d9\'b6\'c8\'b3\'d6\'d0\'f8\'cf\'fa\'ca\'db\'a3\'ac\'bb\'f5\'bc\'dc\'c9\'cf\'b5\'c4\'bf\'e2\'b4\'e6\'d0\'e8\'d2\'aa\'b6\'e0\'c9\'d9\'cc\'ec\'b2\'c5\'c4\'dc\'d3\'c3\'cd\'ea
\f0 \cf0 \cb1 \strokec2 \
\pard\pardeftab720\partightenfactor0
\cf0 \cb4     \cf3 \strokec3 double\cf0 \strokec2  Average_inventory_on_hand = libUncertainFloatUniformDist(\cf6 \strokec6 4.0\cf0 \strokec2 , \cf6 \strokec6 5.0\cf0 \strokec2 );;\cb1 \
\cb4     \cf3 \strokec3 double\cf0 \strokec2  Average_monthly_demand=M;\cb1 \
\cb4     \cf3 \strokec3 double\cf0 \strokec2  Days_of_Supply;\cb1 \
\
\
\cb4     Days_of_Supply = (Average_inventory_on_hand-Average_monthly_demand)*\cf6 \strokec6 30\cf0 \strokec2 ;\cb1 \
\cb4     printf(\cf5 \strokec5 "Days of Supply\\t\\t= %.1E  \\n"\cf0 \strokec2 , Days_of_Supply);\cb1 \
\
\cb4     libUncertainDoublePrint(Days_of_Supply);\cb1 \
\
\
\
\
\
\
\
\
\
\
\
\
\
\pard\pardeftab720\partightenfactor0
\cf7 \cb4 \strokec7 // Days Sales Outstanding\cf0 \cb1 \strokec2 \
\cf7 \cb4 \strokec7 // Days Sales Outstanding = (Receivables/Sales) \'d7 Days in Period\cf0 \cb1 \strokec2 \
\
\cf7 \cb4 \strokec7 // This metric provides a measure of how quickly revenue can be collected from clients. The lower the day\'92s sales outstanding number, the more efficient a business.\cf0 \cb1 \strokec2 \
\
\cf7 \cb4 \strokec7 // 
\f2 \'ce\'b4\'cd\'ea\'b3\'c9\'cf\'fa\'ca\'db\'cc\'ec\'ca\'fd
\f0 \cf0 \cb1 \strokec2 \
\cf7 \cb4 \strokec7 // 
\f2 \'cf\'fa\'ca\'db\'c7\'b7\'bf\'ee\'cc\'ec\'ca\'fd
\f0 =
\f2 \'a3\'a8\'d3\'a6\'ca\'d5\'d5\'cb\'bf\'ee
\f0 /
\f2 \'cf\'fa\'ca\'db\'b6\'ee\'a3\'a9
\f0 \'d7
\f2 \'c6\'da\'bc\'e4\'cc\'ec\'ca\'fd
\f0 \cf0 \cb1 \strokec2 \
\
\cf7 \cb4 \strokec7 // 
\f2 \'d5\'e2\'b8\'f6\'d6\'b8\'b1\'ea\'cc\'e1\'b9\'a9\'c1\'cb\'d2\'bb\'b8\'f6\'ba\'e2\'c1\'bf\'cf\'f2\'bf\'cd\'bb\'a7\'ca\'d5\'c8\'a1\'ca\'d5\'c8\'eb\'b5\'c4\'cb\'d9\'b6\'c8\'a1\'a3\'b5\'b1\'cc\'ec\'b5\'c4\'cf\'fa\'ca\'db\'c7\'b7\'bf\'ee\'ca\'fd\'d7\'d6\'d4\'bd\'b5\'cd\'a3\'ac\'c6\'f3\'d2\'b5\'b5\'c4\'d0\'a7\'c2\'ca\'be\'cd\'d4\'bd\'b8\'df\'a1\'a3
\f0 \cf0 \cb1 \strokec2 \
\
\pard\pardeftab720\partightenfactor0
\cf3 \cb4 \strokec3 double\cf0 \strokec2  Receivables = libUncertainFloatBernoulliDist(\cf6 \strokec6 7\cf0 \strokec2 );\cb1 \
\
\cf3 \cb4 \strokec3 double\cf0 \strokec2  Sales = M;\cb1 \
\
\cf3 \cb4 \strokec3 double\cf0 \strokec2  Days_in_Period=\cf6 \strokec6 30\cf0 \strokec2 ;\cb1 \
\
\cf3 \cb4 \strokec3 double\cf0 \strokec2  Days_Sales_Outstanding=(Receivables/Sales)*Days_in_Period;\cb1 \
\
\
\pard\pardeftab720\partightenfactor0
\cf0 \cb4 printf(\cf5 \strokec5 "Days Sales Outstanding \\t\\t= %.1E  \\n"\cf0 \strokec2 , Days_Sales_Outstanding);\cb1 \
\
\cb4 libUncertainDoublePrint(Days_Sales_Outstanding);\cb1 \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\pard\pardeftab720\partightenfactor0
\cf7 \cb4 \strokec7 // 
\f2 \'b4\'e6\'bb\'f5\'d6\'dc\'d7\'aa\'c2\'ca
\f0 \cf0 \cb1 \strokec2 \
\cf7 \cb4 \strokec7 // 
\f2 \'b4\'e6\'bb\'f5\'d6\'dc\'d7\'aa\'c2\'ca
\f0 =
\f2 \'a3\'a8\'bb\'f5\'ce\'ef\'b3\'c9\'b1\'be
\f0 /
\f2 \'c6\'bd\'be\'f9\'b4\'e6\'bb\'f5\'a3\'a9\'a1\'a3
\f0 \cf0 \cb1 \strokec2 \
\
\cf7 \cb4 \strokec7 // 
\f2 \'bf\'e2\'b4\'e6\'d6\'dc\'d7\'aa\'c2\'ca\'b1\'ed\'ca\'be\'d2\'bb\'b8\'f6\'b9\'ab\'cb\'be\'b5\'c4\'bf\'e2\'b4\'e6\'d6\'dc\'c6\'da\'d4\'da\'d2\'bb\'c4\'ea\'d6\'d0\'b7\'a2\'c9\'fa\'b5\'c4\'b4\'ce\'ca\'fd\'a1\'a3\'b8\'df\'d6\'dc\'d7\'aa\'c2\'ca\'d2\'e2\'ce\'b6\'d7\'c5\'b9\'a9\'d3\'a6\'c1\'b4\'b5\'c3\'b5\'bd\'d3\'d0\'d0\'a7\'b9\'dc\'c0\'ed\'a1\'a3
\f0 \cf0 \cb1 \strokec2 \
\
\pard\pardeftab720\partightenfactor0
\cf0 \cb4     printf(\cf5 \strokec5 "Inventory Turnover \\n"\cf0 \strokec2 );\cb1 \
\
\
\
\
\
\
\
\
\
\pard\pardeftab720\partightenfactor0
\cf3 \cb4 \strokec3 double\cf0 \strokec2  Average_Inventory=libUncertainFloatBetaDist(\cf6 \strokec6 2\cf0 \strokec2 , \cf6 \strokec6 3\cf0 \strokec2 );\cb1 \
\
\cf3 \cb4 \strokec3 double\cf0 \strokec2  Cost_of_Goods=M;\cb1 \
\
\cf3 \cb4 \strokec3 double\cf0 \strokec2  Inventory_Turnover = Cost_of_Goods/Average_Inventory;\cb1 \
\
\
\pard\pardeftab720\partightenfactor0
\cf0 \cb4 printf(\cf5 \strokec5 "Inventory Turnover \\t\\t= %.1E  \\n"\cf0 \strokec2 , Inventory_Turnover);\cb1 \
\
\cb4 libUncertainDoublePrint(Inventory_Turnover);\cb1 \
\
\
\
\
\
\
\
\
\cb4     printf(\cf5 \strokec5 "Customer Order Cycle Time \\n"\cf0 \strokec2 );\cb1 \
\
\
\
\pard\pardeftab720\partightenfactor0
\cf7 \cb4 \strokec7 // 
\f2 \'bf\'cd\'bb\'a7\'b6\'a9\'b5\'a5\'d6\'dc\'c6\'da\'ca\'b1\'bc\'e4
\f0  = (
\f2 \'ca\'b5\'bc\'ca\'bd\'bb\'bb\'f5\'c8\'d5\'c6\'da
\f0  - 
\f2 \'b2\'c9\'b9\'ba\'b6\'a9\'b5\'a5\'b4\'b4\'bd\'a8\'c8\'d5\'c6\'da
\f0 )\cf0 \cb1 \strokec2 \
\
\cf7 \cb4 \strokec7 // 
\f2 \'d5\'e2\'b8\'f6\'b1\'c8\'c2\'ca\'ba\'e2\'c1\'bf\'b5\'c4\'ca\'c7\'d4\'da\'ca\'d5\'b5\'bd\'b2\'c9\'b9\'ba\'b6\'a9\'b5\'a5\'a3\'a8
\f0 PO
\f2 \'a3\'a9\'ba\'f3\'cf\'f2\'bf\'cd\'bb\'a7\'bd\'bb\'b8\'b6\'b6\'a9\'b5\'a5\'cb\'f9\'d0\'e8\'b5\'c4\'ca\'b1\'bc\'e4\'a1\'a3\'d5\'e2\'b8\'f6\'b1\'c8\'c2\'ca\'b5\'c4\'c1\'ed\'d2\'bb\'b8\'f6\'b1\'e4\'cc\'e5\'b1\'ed\'ca\'be\'ce\'aa\'a1\'a3
\f0 \cf0 \cb1 \strokec2 \
\cf7 \cb4 \strokec7 // 
\f2 \'bf\'cd\'bb\'a7\'b6\'a9\'b5\'a5\'d6\'dc\'c6\'da\'ca\'b1\'bc\'e4
\f0  = 
\f2 \'d2\'aa\'c7\'f3\'bd\'bb\'bb\'f5\'c8\'d5\'c6\'da
\f0  - 
\f2 \'b2\'c9\'b9\'ba\'b6\'a9\'b5\'a5\'b4\'b4\'bd\'a8\'c8\'d5\'c6\'da
\f0 \cf0 \cb1 \strokec2 \
\pard\pardeftab720\partightenfactor0
\cf3 \cb4 \strokec3 double\cf0 \strokec2  Actual_delivery_date=M;\cb1 \
\
\cf3 \cb4 \strokec3 double\cf0 \strokec2  Purchase_order_creation_date=\cf6 \strokec6 1\cf0 \strokec2 ;\cb1 \
\
\
\cf3 \cb4 \strokec3 double\cf0 \strokec2  Customer_Order_Cycle_Time = Actual_delivery_date-Purchase_order_creation_date ;\cb1 \
\
\
\pard\pardeftab720\partightenfactor0
\cf0 \cb4 printf(\cf5 \strokec5 "Customer Order Cycle Time \\t\\t= %.1E  \\n"\cf0 \strokec2 , Customer_Order_Cycle_Time);\cb1 \
\
\cb4 libUncertainDoublePrint(Customer_Order_Cycle_Time);\cb1 \
\
\
\
\
\
\
\
\
\
\
\cb4 printf(\cf5 \strokec5 "Gross Margin Return on Investment \\n"\cf0 \strokec2 );\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf7 \cb4 \strokec7 // 
\f2 \'cd\'b6\'d7\'ca\'c3\'ab\'c0\'fb\'bb\'d8\'b1\'a8\'c2\'ca\'a3\'a8
\f0 GMROI
\f2 \'a3\'a9
\f0 =[
\f2 \'c3\'ab\'c0\'fb
\f0 ]/[
\f2 \'a3\'a8\'c6\'da\'b3\'f5\'bf\'e2\'b4\'e6
\f0 -
\f2 \'c6\'da\'c4\'a9\'bf\'e2\'b4\'e6\'a3\'a9
\f0 /2] \'d7100\cf0 \cb1 \strokec2 \
\
\cf7 \cb4 \strokec7 // GMROI
\f2 \'b1\'c8\'c2\'ca\'b1\'ed\'c3\'f7\'c1\'cb\'d4\'da\'bf\'e2\'b4\'e6\'b7\'bd\'c3\'e6\'b5\'c4\'c3\'bf\'cf\'ee\'c6\'bd\'be\'f9\'cd\'b6\'d7\'ca\'cb\'f9\'bb\'f1\'b5\'c3\'b5\'c4\'c3\'ab\'c0\'fb\'a1\'a3\'d2\'d4\'d4\'c2\'b6\'c8\'ce\'aa\'d6\'dc\'c6\'da\'b8\'fa\'d7\'d9\'d5\'e2\'d2\'bb\'d6\'b8\'b1\'ea\'a3\'ac\'d3\'d0\'d6\'fa\'d3\'da\'c8\'b7\'b6\'a8\'c4\'c4\'b8\'f6\'cf\'ee\'c4\'bf\'d4\'da\'bf\'e2\'b4\'e6\'d6\'d0\'b2\'fa\'c9\'fa\'bd\'cf\'b8\'df\'b5\'c4\'c3\'ab\'c0\'fb\'a1\'a3
\f0 \cf0 \cb1 \strokec2 \
\
\
\
\
\
\
\pard\pardeftab720\partightenfactor0
\cf3 \cb4 \strokec3 double\cf0 \strokec2  Gross_Profit=M;\cb1 \
\
\cf3 \cb4 \strokec3 double\cf0 \strokec2  Opening_Stock=\cf6 \strokec6 3\cf0 \strokec2 *M;\cb1 \
\
\
\cf3 \cb4 \strokec3 double\cf0 \strokec2  Closing_Stock=\cf6 \strokec6 2\cf0 \strokec2 *M;\cb1 \
\
\
\cf3 \cb4 \strokec3 double\cf0 \strokec2  GMROI = Gross_Profit/((Opening_Stock-Closing_Stock)/\cf6 \strokec6 2\cf0 \strokec2 )*\cf6 \strokec6 100\cf0 \strokec2 ;\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf0 \cb4 printf(\cf5 \strokec5 "GMROI \\t\\t= %.1E  \\n"\cf0 \strokec2 , GMROI);\cb1 \
\
\cb4 libUncertainDoublePrint(GMROI);\cb1 \
\
\
\
\
\
\
\
\
\cb4     printf(\cf5 \strokec5 "Turn-Earn Index \\n"\cf0 \strokec2 );\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf3 \cb4 \strokec3 double\cf0 \strokec2  ITR=M;\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf7 \cb4 \strokec7 //double Gross_Profit =libUncertainFloatBetaDist(2,2.5);\cf0 \cb1 \strokec2 \
\
\
\pard\pardeftab720\partightenfactor0
\cf3 \cb4 \strokec3 double\cf0 \strokec2  TEI = ITR*Gross_Profit*\cf6 \strokec6 100\cf0 \strokec2 ;\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf0 \cb4 printf(\cf5 \strokec5 "TEI \\t\\t= %.1E  \\n"\cf0 \strokec2 , TEI);\cb1 \
\
\cb4 libUncertainDoublePrint(TEI);\cb1 \
\
\
\
\
\
\
\
\cb4     printf(\cf5 \strokec5 "On Time Shipping Rate \\n"\cf0 \strokec2 );\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf3 \cb4 \strokec3 double\cf0 \strokec2  Number_of_On_Time_Items=M*M;\cb1 \
\cf3 \cb4 \strokec3 double\cf0 \strokec2  Total_Items=\cf6 \strokec6 30\cf0 \strokec2 ;\cb1 \
\
\cf3 \cb4 \strokec3 double\cf0 \strokec2  On_Time_Shipping_Rate = ( Number_of_On_Time_Items/ Total_Items)*\cf6 \strokec6 100\cf0 \strokec2 ;\cb1 \
\pard\pardeftab720\partightenfactor0
\cf0 \cb4 printf(\cf5 \strokec5 "On Time Shipping Rate \\t\\t= %.1E  \\n"\cf0 \strokec2 , On_Time_Shipping_Rate);\cb1 \
\
\
\
\cb4     printf(\cf5 \strokec5 "Fill Rate \\n"\cf0 \strokec2 );\cb1 \
\
\
\cb4     printf(\cf5 \strokec5 "Average Payment Period for Production Materials \\n"\cf0 \strokec2 );\cb1 \
\
\
\
\cb4     printf(\cf5 \strokec5 "Supply Chain Cycle Time \\n"\cf0 \strokec2 );\cb1 \
\
\
\cb4     printf(\cf5 \strokec5 "Inventory Days of Supply \\n"\cf0 \strokec2 );\cb1 \
\
\
\
\cb4     printf(\cf5 \strokec5 "Freight cost per unit \\n"\cf0 \strokec2 );\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf7 \cb4 \strokec7 // 
\f2 \'c3\'bf\'b5\'a5\'ce\'bb\'b5\'c4\'d4\'cb\'b7\'d1
\f0 \cf0 \cb1 \strokec2 \
\cf7 \cb4 \strokec7 // 
\f2 \'c3\'bf\'b5\'a5\'ce\'bb\'bb\'f5\'d4\'cb\'b3\'c9\'b1\'be
\f0 =
\f2 \'a3\'a8\'d7\'dc\'bb\'f5\'d4\'cb\'b3\'c9\'b1\'be
\f0 /
\f2 \'ce\'ef\'c6\'b7\'ca\'fd\'c1\'bf\'a3\'a9
\f0 \cf0 \cb1 \strokec2 \
\
\cf7 \cb4 \strokec7 // SCM
\f2 \'b5\'c4\'c4\'bf\'b1\'ea\'ca\'c7\'d7\'ee\'d0\'a1\'bb\'af\'d5\'e2\'d2\'bb\'b5\'a5\'ce\'bb\'b3\'c9\'b1\'be\'a3\'ac\'d2\'d4\'ca\'b5\'cf\'d6\'d4\'cb\'d3\'aa\'d0\'a7\'c2\'ca\'a1\'a3
\f0 \cf0 \cb1 \strokec2 \
\
\cf7 \cb4 \strokec7 // Freight cost per unit = (Total freight cost / Number of items)\cf0 \cb1 \strokec2 \
\
\cf7 \cb4 \strokec7 // The SCM aims to minimize this cost per unit to achieve operational efficiency.\cf0 \cb1 \strokec2 \
\
\
\
\
\pard\pardeftab720\partightenfactor0
\cf3 \cb4 \strokec3 double\cf0 \strokec2  Total_freight_cost=M;\cb1 \
\cf3 \cb4 \strokec3 double\cf0 \strokec2  Number_of_items=\cf6 \strokec6 20\cf0 \strokec2 ;\cb1 \
\
\cf3 \cb4 \strokec3 double\cf0 \strokec2  Freight_cost_per_unit=Total_freight_cost/Number_of_items; \cb1 \
\
\
\pard\pardeftab720\partightenfactor0
\cf0 \cb4     printf(\cf5 \strokec5 "Freight cost per unit \\t\\t= %.1E  \\n"\cf0 \strokec2 , Freight_cost_per_unit);\cb1 \
\
\cb4     libUncertainDoublePrint(Freight_cost_per_unit);\cb1 \
\
\
\cb4     \cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf7 \cb4 \strokec7 // Freight bill accuracy = (error-free freight bills / total freight bills) \'d7 100\cf0 \cb1 \strokec2 \
\
\cf7 \cb4 \strokec7 // This number shows the percentage of error-free freight bills. Accuracy in matters of billing is crucial for profitability and for the satisfaction of customers.\cf0 \cb1 \strokec2 \
\
\
\cf7 \cb4 \strokec7 // 
\f2 \'bb\'f5\'d4\'cb\'b5\'a5\'be\'dd\'d7\'bc\'c8\'b7\'c2\'ca
\f0 =
\f2 \'a3\'a8\'ce\'de\'b4\'ed\'ce\'f3\'bb\'f5\'d4\'cb\'b5\'a5\'be\'dd
\f0 /
\f2 \'d7\'dc\'bb\'f5\'d4\'cb\'b5\'a5\'be\'dd\'a3\'a9
\f0 \'d7100\cf0 \cb1 \strokec2 \
\
\cf7 \cb4 \strokec7 // 
\f2 \'d5\'e2\'b8\'f6\'ca\'fd\'d7\'d6\'cf\'d4\'ca\'be\'c1\'cb\'ce\'de\'b2\'ee\'b4\'ed\'bb\'f5\'d4\'cb\'d5\'cb\'b5\'a5\'b5\'c4\'b0\'d9\'b7\'d6\'b1\'c8\'a1\'a3\'d5\'cb\'b5\'a5\'ca\'c2\'cf\'ee\'b5\'c4\'d7\'bc\'c8\'b7\'d0\'d4\'b6\'d4\'d3\'af\'c0\'fb\'c4\'dc\'c1\'a6\'ba\'cd\'bf\'cd\'bb\'a7\'c2\'fa\'d2\'e2\'b6\'c8\'d6\'c1\'b9\'d8\'d6\'d8\'d2\'aa\'a1\'a3
\f0 \cf0 \cb1 \strokec2 \
\
\pard\pardeftab720\partightenfactor0
\cf3 \cb4 \strokec3 double\cf0 \strokec2  error_free_freight_bills=M;\cb1 \
\cf3 \cb4 \strokec3 double\cf0 \strokec2  total_freight_bills=\cf6 \strokec6 6\cf0 \strokec2 ;\cb1 \
\cf3 \cb4 \strokec3 double\cf0 \strokec2  Freight_bill_accuracy = (error_free_freight_bills/total_freight_bills)*\cf6 \strokec6 100\cf0 \strokec2 ;\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf0 \cb4     printf(\cf5 \strokec5 "Freight bill accuracy \\t\\t= %.1E  \\n"\cf0 \strokec2 , Freight_bill_accuracy);\cb1 \
\
\cb4     libUncertainDoublePrint(Freight_bill_accuracy);\cb1 \
\
\
\cb4     \cf3 \strokec3 return\cf0 \strokec2  \cf6 \strokec6 0\cf0 \strokec2 ;\cb1 \
\cb4 \}\cb1 \
\
\
}