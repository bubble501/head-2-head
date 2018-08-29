import { CollectModule } from './collect.module';

describe('CollectModule', () => {
  let collectModule: CollectModule;

  beforeEach(() => {
    collectModule = new CollectModule();
  });

  it('should create an instance', () => {
    expect(collectModule).toBeTruthy();
  });
});
