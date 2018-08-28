import { TakerModule } from './taker.module';

describe('TakerModule', () => {
  let takerModule: TakerModule;

  beforeEach(() => {
    takerModule = new TakerModule();
  });

  it('should create an instance', () => {
    expect(takerModule).toBeTruthy();
  });
});
