import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { MakerHolderComponent } from './maker-holder.component';

describe('MakerHolderComponent', () => {
  let component: MakerHolderComponent;
  let fixture: ComponentFixture<MakerHolderComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ MakerHolderComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(MakerHolderComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
