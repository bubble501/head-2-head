import { WagersModule } from './wagers.module';

describe('WagersModule', () => {
  let wagersModule: WagersModule;

  beforeEach(() => {
    wagersModule = new WagersModule();
  });

  it('should create an instance', () => {
    expect(wagersModule).toBeTruthy();
  });
});
