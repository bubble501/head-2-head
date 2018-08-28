import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { TakerHolderComponent } from './taker-holder.component';

describe('TakerHolderComponent', () => {
  let component: TakerHolderComponent;
  let fixture: ComponentFixture<TakerHolderComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ TakerHolderComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(TakerHolderComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
