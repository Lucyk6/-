interface IPaymentMethod
{
    bool Pay(decimal amount);
}

class CardPayment : IPaymentMethod
{
    public bool Pay(decimal amount)
    {
        if (amount > 0)
        {
            Console.WriteLine("ОПЛАТА ПРОШЛА");
            return true;
        }
        else
        {
            Console.WriteLine("Ошибка: сумма оплаты должна быть больше нуля");
            return false;
        }
    }
}
class CryptoPayment : IPaymentMethod
{
    public bool Pay(decimal amount)
    {
        if (amount > 0)
        {
            Console.WriteLine("ТРАНЗАКЦИЯ В БЛОКЧАЙНЕ ПОДТВЕРЖДЕНА");
            return true;
        }
        else
        {
            Console.WriteLine("Ошибка: сумма транзакции должна быть больше нуля");
            return false;
        }
    }
}
class Order
{
    public int number { get; set; }
    public int amount { get; set; }
    public int status { get; set; }
    event Action<Order>? OnStatusChanged;
    public void Process ( IPaymentMethod method)
    {
        method.Pay(amount);

        OnStatusChanged?.Invoke(this);
    }
}
class Followers
{
   

}
