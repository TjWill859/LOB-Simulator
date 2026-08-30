#include <chrono>
#include <cstdint>

enum class OrderSide
{
    Buy,
    Sell
};

enum class OrderType
{
    Limit,
    Market
};

struct Order
{
    using Timestamp = std::chrono::system_clock::time_point;

    std::uint64_t id;
    OrderSide side;
    OrderType type;
    double price;
    std::uint64_t quantity;
    std::uint64_t filled;
    Timestamp timestamp;

    static std::uint64_t nextId()
    {
        static std::uint64_t currentId = 1;
        return currentId++;
    }

    Order(OrderSide side_, OrderType type_, double price_, std::uint64_t quantity_,
          Timestamp timestamp_ = std::chrono::system_clock::now())
        : id(nextId()),
          side(side_),
          type(type_),
          price(price_),
          quantity(quantity_),
          filled(0),
          timestamp(timestamp_)
    {
    }

    [[nodiscard]] std::uint64_t remainingQuantity() const
    {
        return quantity - filled;
    }

    [[nodiscard]] bool isFullyFilled() const
    {
        return filled >= quantity;
    }
};
