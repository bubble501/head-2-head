import { MakerModule } from './maker.module';

describe('MakerModule', () => {
  let makerModule: MakerModule;

  beforeEach(() => {
    makerModule = new MakerModule();
  });

  it('should create an instance', () => {
    expect(makerModule).toBeTruthy();
  });
});
