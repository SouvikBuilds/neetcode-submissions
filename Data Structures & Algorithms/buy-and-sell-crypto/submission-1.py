class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        currentProfit = 0
        maxProfit = 0 
        minPrice = prices[0]

        for i in range(0,len(prices)):
            price = prices[i]

            if currentProfit > maxProfit:
                maxProfit = currentProfit

            currentProfit = price-minPrice

            
            
            if price < minPrice:
                minPrice = price
        
        return max(currentProfit,maxProfit)