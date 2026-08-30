#pragma once

#include <cstdint>

using OrderId = std::uint64_t;
using Timestamp = std::uint64_t; // Unix timestamp in milliseconds
using Price = std::int64_t; // Price in smallest currency unit (e.g., cents)
using Quantity = std::int32_t; // Quantity in smallest unit (e.g., shares, contracts)

enum class Side { Buy, Sell };
enum class OrderType { Limit, Market };

struct Order
{
    OrderId id;
    Side side;
    OrderType type;
    Price price;
    Quantity quantity;
    Quantity filledQuantity;
    Timestamp timestamp;
};

struct Trade
{
    Price price;
    Quantity quantity;
    Timestamp timestamp;
    OrderId restingOrderId;
    OrderId aggressorOrderId;
    Side aggressorSide;
};