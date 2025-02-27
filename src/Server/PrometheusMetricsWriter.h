#pragma once

#include <string>

#include <Common/AsynchronousMetrics.h>
#include <IO/WriteBuffer.h>

#include <Poco/Util/AbstractConfiguration.h>


namespace DB
{

/// Write metrics in Prometheus format
class PrometheusMetricsWriter
{
public:
    PrometheusMetricsWriter(
        const Poco::Util::AbstractConfiguration & config, const std::string & config_name,
        const AsynchronousMetrics & async_metrics_);

    void write(WriteBuffer & wb) const;

private:
    const AsynchronousMetrics & async_metrics;

    const bool send_events;
    const bool send_metrics;
    const bool send_asynchronous_metrics;
    const bool send_errors;

    static inline constexpr auto profile_events_prefix = "ClickHouseProfileEvents_";
    static inline constexpr auto current_metrics_prefix = "ClickHouseMetrics_";
    static inline constexpr auto asynchronous_metrics_prefix = "ClickHouseAsyncMetrics_";
    static inline constexpr auto error_metrics_prefix = "ClickHouseErrorMetric_";
};

}
