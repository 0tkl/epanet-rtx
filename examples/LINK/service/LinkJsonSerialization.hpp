#ifndef LinkJsonSerialization_hpp
#define LinkJsonSerialization_hpp

#include "rtxMacros.h"

#include "Units.h"
#include "TimeSeries.h"
#include "TimeSeriesFilter.h"
#include "ConcreteDbRecords.h"

#include <cpprest/json.h>

namespace RTX {
  
  class SerializerJson : public BaseVisitor,
  public Visitor<Units>,
  public Visitor<Clock>,
  public Visitor<TimeSeries>,
  public Visitor<TimeSeriesFilter>,
  public Visitor<PointRecord>,
  public Visitor<DbPointRecord>,
  public Visitor<SqlitePointRecord>,
  public Visitor<InfluxDbPointRecord>,
  public Visitor<InfluxUdpPointRecord>,
  public Visitor<OdbcPointRecord>
  {
  public:
    static web::json::value to_json(RTX_object::_sp obj);
    static web::json::value to_json(RTX_object& obj);
    static web::json::value to_json(std::vector<RTX_object::_sp> objVec);
    
    SerializerJson();
    void visit(Units &u);
    void visit(Clock &c);
    void visit(TimeSeries &ts);
    void visit(TimeSeriesFilter &ts);
    void visit(PointRecord &pr);
    void visit(DbPointRecord &pr);
    void visit(SqlitePointRecord &pr);
    void visit(InfluxDbPointRecord &pr);
    void visit(InfluxUdpPointRecord &pr);
    void visit(OdbcPointRecord &pr);
    web::json::value json();
    
  private:
    web::json::value _v;
  };
  
  
  class DeserializerJson : public BaseVisitor,
  public Visitor<Units>,
  public Visitor<Clock>,
  public Visitor<TimeSeries>,
  public Visitor<TimeSeriesFilter>,
  public Visitor<PointRecord>,
  public Visitor<DbPointRecord>,
  public Visitor<SqlitePointRecord>,
  public Visitor<InfluxDbPointRecord>,
  public Visitor<InfluxUdpPointRecord>,
  public Visitor<OdbcPointRecord>,
  {
  public:
    static RTX_object::_sp from_json(web::json::value json);
    static std::vector<RTX_object::_sp> from_json_array(web::json::value json);
    
    // analytics
    static TimeSeries::_sp analyticWithJson(web::json::value jsonValue, std::vector<TimeSeries::_sp> cadidateSeries);

    DeserializerJson(web::json::value withJson);
    void visit(Units &u);
    void visit(Clock &c);
    void visit(TimeSeries &ts);
    void visit(TimeSeriesFilter &ts);
    void visit(PointRecord &pr);
    void visit(DbPointRecord &pr);
    void visit(SqlitePointRecord &pr);
    void visit(InfluxDbPointRecord &pr);
    void visit(InfluxUdpPointRecord &pr);
    void visit(OdbcPointRecord &pr);
    
  private:
    web::json::value _v;
  };
}
#endif /* LinkJsonSerialization_hpp */
