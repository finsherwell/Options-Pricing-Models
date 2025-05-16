# Options-Pricing-Models
Below I will talk through what each pricing model is, explaining it in really simple terms. I will be implementing the 3 options pricing models in C++, then use a Python notebook to implement these algorithms using extracted data. The notebook will allow me to analyse, visualise and explore the performance and efficiency of these algorithms.

## Black-Scholes Model
Developed mainly for pricing European stocks, the Black-Scholes model prices options by taking in many variables to calculate the fair price of an option. It is like a very smart calculator, invented in 1973 by economists Fischer Black and Myron Scholes. However, it can only be used on the expiration date - like a ticket that only works on one specific day.

*Think of it like:*
- You are buying a movie ticket today that lets you watch a movie a month from now - **only on that one day**. You want to know: **how much is this ticket worth today**, considering how popular (or not) the movie might be then?
Black-Scholes helps to answer that.

**What does the model assume?**

Assumptions about the Asset Behaviour:
1. Returns are normally distributed and independent:
   - The model assumes the stock's daily changes are like coin flips - random, not influenced by yesterday's results. An analogy is just because it rained yesterday, doesn't guarantee today will be sunny or rainy.
2. Volatility is constant:
   - This means the asset's volatility stays steady over time. An analogy is imagine the stock is like a person. If they have a calm personality, it won't get anxious overnight - it stays predictable.
3. Future dividends are known:
   - A model can work better if we already know exactly how much cash (dividends) the company will pay out. For example, you know the movie theater gives out a £5 coupon at the end - and you plan for that in the ticket's value.

Assumptions about the Economy:
1. Risk-free interest rate is known and constant:
   - This is like a guaranteed bank savings rate you can always count on. For example, you know your money will grow at 5% if you just leave it in a bank - no surprises.
2. No taxes or transaction costs:
   - The model assumes trading is completely free.
3. You can borrow or short-sell easily:
   - Allows traders to create a risk-free hedge by combining stock and option positions - sometimes needing to borrow stock (short-sell) or borrow moneyto balance their bets. If borrowing were expensive or restricted, the maths wouldn't work as cleanly.
   - An example of hedging could be owning stock in an airline, but worrying about oil prices rising. To hedge against fuel cost spikes, you could buy a oil futures.

**The Forumla's Core and Inputs:**
- S = Asset Price: Price that the underlying asset is trading at today.
- K = Strike Price: Price you can buy that asset for.
- T = Time to Expiry: How long until the option expires.
- σ = Volatility: How wildly the stock is moving.
- r = Risk-Free Rate: The interest rate from a "perfect" investment.
- δ = Dividend Yield: How much the stock pays in dividends.

The formula has **two key parts**:
1. N(d1) = Probability the option ends up profitable:
   - This tells us: **What's the chance the asset goes above the strike price?**
2. N(d2) = Probability the option will actually be exercised:
   - This tells us: **What's the chance the option ends up valuable enough to bother using?**

These use normal distribution curves to account for risk-adjusted probabilities - meaning they factor in not just what could happen, but what is worth betting on in the real world.

**The Formula:**
For a Call Option (the right to buy the stock):
- $`C = S ⋅ e^{-δT} ⋅ N(d1) - K ⋅ e^{-rT} ⋅ N(d2)`$

You get the expected value of the stock adjusted for dividends, minus what you'd use to pay to use the option, adjusted for interest rates.

Think of it as:
- "What I expect to get" minus "what it costs me".

For a Put Option (the right to sell the stock):
- $`P = K ⋅ e^{-rT} ⋅ N(-d2) - S ⋅ e^{-δT} ⋅ N(-d1)`$

Flip the logic: now you expect to **sell** the stock, so the payout maths reverses.

**Limitations:**
The original Black-Scholes model:
- Only worls for European options (you can't use the option early).
- Doesn't handle sudden jumps or crashes (volatility is always smooth).
- Assumes a perfect world - no fees, perfect borrowing, etc.

## Binomial Model
Think of it as a decision tree for the future:
- The Binomial Model imagines that the price of a stock doesn't move randomly in every possible way, but instead steps up or down in a **predictable, structured way** over time - like climbing a ladder, one rung at a time, either higher or lower.
It breaks time into small intervals, and at each one, the stock price can either go up by a certain percentage or down by a certain percentage. By looking at all the possible paths and outcomes, it works backward from the final payoffs to figure out the fair price of the option today.

**How it Works:**
1. Assume the stock can go UP or DOWN each time step.
   - The amount it goes up or down is based on volatility.
   - For example: in each step, the price goes up by 10% or down by 9%.
2. Build a price tree.
   - You simulate all possible paths the stock can take.
   - After a few steps, it looks like a branching tree with many future prices.
3. Calculate option payoff at the end (leaf nodes).
   - If its a call option: **Payoff = max(Stock Price - Strike Price, 0)**
   - If its a put option: **Payoff = max(Strike Price - Stock Price, 0)**
4. Work backward to today:
   - Use risk-neutral probabilities to figure out the expected value at each earlier point.
   - Then discount (reduce) those values back to today's dollars using the risk-free rate.
5. **Result:** You get the option's fair price today.

**Why is it used?**

Unlike the Black-Scholes model:
- It can handle American options.
- It is easier to adapt for things like dividends, changing interest rates, or barriers.
- It gives you a step-by-step visual model - great for intuition.

A Real-World Analogy - Buying and Selling Umbrellas:
- You are a store selling umbrellas over 3 days. The weather can get sunnier or rainier each day. You build a tree showing all possible weather paths and how many umbrellas you'd sell. Then you ask:

*Knowing how all this could potentially go, how much is a box of umbrellas worth today if I want to make a profit?*

That is binomial pricing - looking at every possibility, and working backwards.

## Monte-Carlo Simulation
