package org.inesctec.flexcomm.ofexp.api;

import org.onosproject.event.AbstractEvent;

public class FlexcommEvent extends AbstractEvent<FlexcommEvent.Type, FlexcommStatistics> {

  public enum Type {
    GLOBAL_STATS_UPDATED,
    PORT_STATS_UPDATED,
  }

  public FlexcommEvent(Type type, FlexcommStatistics stats) {
    super(type, stats);
  }

  public FlexcommEvent(Type type, FlexcommStatistics stats, long time) {
    super(type, stats, time);
  }
}