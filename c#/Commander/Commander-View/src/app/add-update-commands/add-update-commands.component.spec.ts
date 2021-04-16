import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { AddUpdateCommandsComponent } from './add-update-commands.component';

describe('AddUpdateCommandsComponent', () => {
  let component: AddUpdateCommandsComponent;
  let fixture: ComponentFixture<AddUpdateCommandsComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ AddUpdateCommandsComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(AddUpdateCommandsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
