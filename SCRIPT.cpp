

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <uncertain.h>
#include <stddef.h>
#include <uncertain.h>


static void
loadInputs(double *  G, double *  M, double *  Rs, double *  b, double *  gamma, double *  phi)
{
    double empiricalTaylorFactorValues[] = {
                        3.2,
                        3.9,
                        4.1,
                        3.2,
                        3.8,
                        3.8,
                        2.1,
                        3.0,
                        1.9,
                        3.9,
                        2.3,
                        2.2,
                        3.2,
                        2.2,
                        3.9,
                        2.2,
                        1.9,
                        3.2,
                        3.9,
                        3.1,
                    };

    *M      = libUncertainDoubleDistFromSamples(
                                empiricalTaylorFactorValues,
                                sizeof(empiricalTaylorFactorValues)/sizeof(double)
                            );
    *G      = 7E10;
    *Rs     = 2E-8;
    *b      = 2.54E-10;
    *gamma  = 0.2;
    *phi    = 0.375;
}

int
main(int argc, char *   argv[])
{
    double  G, M, Rs, b, gamma, phi, sigmaC;


    loadInputs(&G, &M, &Rs, &b, &gamma, &phi);

    /*
     *                    ⎛    _________________    ⎞
     *       ⎛ M ⋅ γ  ⎞   ⎜   ╱8.0 ⋅ γ ⋅ φ ⋅ Rs     ⎟
     *  σ  = ⎜─────── ⎟ ⋅ ⎜  ╱ ───────────────── - φ⎟
     *   c   ⎝2.0 ⋅ b ⎠   ⎝╲╱  π ⋅ G ⋅ pow(b, 2)    ⎠
     */
    sigmaC = (100-M)/100;


//     Perfect Order Measurement = [(Total orders – Error orders) / Total orders] × 100

// This metric is important as it calculates the percentage of orders that are free from errors.  It calculates the rate of error-free delivery for each stage of a purchase order. These errors can be in the form of procurement forecasting error, warehouse pickup processing error, invoicing error, shipping order errors, etc. It can be broken down stage-wise as:

// 99.98 percent perfect for warehousing
// 99.02 percent perfect for transportation
// 99.12 percent perfect for production
// 99.99 percent perfect for procurement
    //printf(" %d \n", sigmaC);

    printf("Perfect Order Measurement is\t\t= %.1E  \n", sigmaC);

    libUncertainDoublePrint(sigmaC);


// Inventory Turnover Ratio (ITR) = Cost of Goods/ [(Opening Stock – Closing Stock) / 2]

// The Inventory Turnover ratio helps determine the number of times a company sells or turns the average inventory that is kept in the storehouses. Therefore, in other words, it is a measure of opportunities to make profits from the working capital that is invested in the form of inventory.



//Inventory Turnover Ratio (ITR) = Cost of Goods/ [(Opening Stock – Closing Stock) / 2]




    double inventoryTurnOverRate;
    double costOfGoods=100;
    double openStock = 100;

    inventoryTurnOverRate = 30 / ((100-M)/2);

    //printf("Inventory Turnover Ratio \n");

    printf("Inventory Turnover Ratio \t\t= %.1E  \n", inventoryTurnOverRate);


    libUncertainDoublePrint(inventoryTurnOverRate);


// Cash to Cash Cycle Time
// Cash to Cash Cycle Time = Materials payment date – Customer order payment date

// This ratio measures the number of days between the payment of materials to the getting the payment for the product. It is averaged on a weekly, monthly or quarterly basis. The ratio tells of the amount of time the operating capital is tied up for and it is important from the point of view that cash tied up is unavailable for use for other purposes. A smooth cash to cash operation denotes a supply chain that is profitable.






   

    double Materials_payment_date = 8;
    double Customer_order_payment_date=M;
    double Cash_to_Cash_Cycle_Time=Materials_payment_date-Customer_order_payment_date;

     printf("Cash to Cash Cycle Time is\t\t= %.1E  \n", Cash_to_Cash_Cycle_Time);
    libUncertainDoublePrint(Cash_to_Cash_Cycle_Time);
    
    //printf("Alloy strength (σc)\t\t= %.1E MPa\n", sigmaC/1000000);
    

// Days of Supply = [Average inventory on hand (as value) / Average monthly demand (as value)] × 30 (for measurement on a monthly basis)

// This forms one of the key performance indicators that measure the efficiency in supply chain.


//printf("Days of Supply \n");

//如果销售继续以与近期销售相同的速度持续销售，货架上的库存需要多少天才能用完
    double Average_inventory_on_hand = libUncertainFloatUniformDist(4.0, 5.0);;
    double Average_monthly_demand=M;
    double Days_of_Supply;


    Days_of_Supply = (Average_inventory_on_hand-Average_monthly_demand)*30;
    printf("Days of Supply\t\t= %.1E  \n", Days_of_Supply);

    libUncertainDoublePrint(Days_of_Supply);













// Days Sales Outstanding
// Days Sales Outstanding = (Receivables/Sales) × Days in Period

// This metric provides a measure of how quickly revenue can be collected from clients. The lower the day’s sales outstanding number, the more efficient a business.

// 未完成销售天数
// 销售欠款天数=（应收账款/销售额）×期间天数

// 这个指标提供了一个衡量向客户收取收入的速度。当天的销售欠款数字越低，企业的效率就越高。

double Receivables = libUncertainFloatBernoulliDist(7);

double Sales = M;

double Days_in_Period=30;

double Days_Sales_Outstanding=(Receivables/Sales)*Days_in_Period;


printf("Days Sales Outstanding \t\t= %.1E  \n", Days_Sales_Outstanding);

libUncertainDoublePrint(Days_Sales_Outstanding);


















// 存货周转率
// 存货周转率=（货物成本/平均存货）。

// 库存周转率表示一个公司的库存周期在一年中发生的次数。高周转率意味着供应链得到有效管理。

    printf("Inventory Turnover \n");









double Average_Inventory=libUncertainFloatBetaDist(2, 3);

double Cost_of_Goods=M;

double Inventory_Turnover = Cost_of_Goods/Average_Inventory;


printf("Inventory Turnover \t\t= %.1E  \n", Inventory_Turnover);

libUncertainDoublePrint(Inventory_Turnover);








    printf("Customer Order Cycle Time \n");



// 客户订单周期时间 = (实际交货日期 - 采购订单创建日期)

// 这个比率衡量的是在收到采购订单（PO）后向客户交付订单所需的时间。这个比率的另一个变体表示为。
// 客户订单周期时间 = 要求交货日期 - 采购订单创建日期
double Actual_delivery_date=M;

double Purchase_order_creation_date=1;


double Customer_Order_Cycle_Time = Actual_delivery_date-Purchase_order_creation_date ;


printf("Customer Order Cycle Time \t\t= %.1E  \n", Customer_Order_Cycle_Time);

libUncertainDoublePrint(Customer_Order_Cycle_Time);










printf("Gross Margin Return on Investment \n");

// 投资毛利回报率（GMROI）=[毛利]/[（期初库存-期末库存）/2] ×100

// GMROI比率表明了在库存方面的每项平均投资所获得的毛利。以月度为周期跟踪这一指标，有助于确定哪个项目在库存中产生较高的毛利。






double Gross_Profit=M;

double Opening_Stock=3*M;


double Closing_Stock=2*M;


double GMROI = Gross_Profit/((Opening_Stock-Closing_Stock)/2)*100;

printf("GMROI \t\t= %.1E  \n", GMROI);

libUncertainDoublePrint(GMROI);








    printf("Turn-Earn Index \n");

double ITR=M;

//double Gross_Profit =libUncertainFloatBetaDist(2,2.5);


double TEI = ITR*Gross_Profit*100;

printf("TEI \t\t= %.1E  \n", TEI);

libUncertainDoublePrint(TEI);







    printf("On Time Shipping Rate \n");

double Number_of_On_Time_Items=M*M;
double Total_Items=30;

double On_Time_Shipping_Rate = ( Number_of_On_Time_Items/ Total_Items)*100;
printf("On Time Shipping Rate \t\t= %.1E  \n", On_Time_Shipping_Rate);



    printf("Fill Rate \n");


    printf("Average Payment Period for Production Materials \n");



    printf("Supply Chain Cycle Time \n");


    printf("Inventory Days of Supply \n");



    printf("Freight cost per unit \n");

// 每单位的运费
// 每单位货运成本=（总货运成本/物品数量）

// SCM的目标是最小化这一单位成本，以实现运营效率。

// Freight cost per unit = (Total freight cost / Number of items)

// The SCM aims to minimize this cost per unit to achieve operational efficiency.




double Total_freight_cost=M;
double Number_of_items=20;

double Freight_cost_per_unit=Total_freight_cost/Number_of_items; 


    printf("Freight cost per unit \t\t= %.1E  \n", Freight_cost_per_unit);

    libUncertainDoublePrint(Freight_cost_per_unit);


    

// Freight bill accuracy = (error-free freight bills / total freight bills) × 100

// This number shows the percentage of error-free freight bills. Accuracy in matters of billing is crucial for profitability and for the satisfaction of customers.


// 货运单据准确率=（无错误货运单据/总货运单据）×100

// 这个数字显示了无差错货运账单的百分比。账单事项的准确性对盈利能力和客户满意度至关重要。

double error_free_freight_bills=M;
double total_freight_bills=6;
double Freight_bill_accuracy = (error_free_freight_bills/total_freight_bills)*100;

    printf("Freight bill accuracy \t\t= %.1E  \n", Freight_bill_accuracy);

    libUncertainDoublePrint(Freight_bill_accuracy);


    return 0;
}


