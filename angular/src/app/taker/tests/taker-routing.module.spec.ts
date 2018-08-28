import { TakerRoutingModule } from './taker-routing.module';

describe('TakerRoutingModule', () => {
  let takerRoutingModule: TakerRoutingModule;

  beforeEach(() => {
    takerRoutingModule = new TakerRoutingModule();
  });

  it('should create an instance', () => {
    expect(takerRoutingModule).toBeTruthy();
  });
});
