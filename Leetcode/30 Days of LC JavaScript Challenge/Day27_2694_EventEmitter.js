class EventEmitter {
  constructor() {
    this.events = {};
  }

  subscribe(event, cb) {
    if (!(event in this.events)) {
      this.events[event] = new Set([cb]);
    } else {
      this.events[event].add(cb);
    }

    return {
      unsubscribe: () => {
        this.events[event].delete(cb);
      },
    };
  }

  emit(event, args = []) {
    if (!(event in this.events)) return [];
    const result = [];
    this.events[event].forEach((fn) => {
      result.push(fn(...args));
    });
    return result;
  }
}
