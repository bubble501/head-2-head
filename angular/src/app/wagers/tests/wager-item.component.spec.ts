import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { WagerItemComponent } from './wager-item.component';

describe('WagerItemComponent', () => {
  let component: WagerItemComponent;
  let fixture: ComponentFixture<WagerItemComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ WagerItemComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(WagerItemComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
